/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 05:49:07 by achazal           #+#    #+#             */
/*   Updated: 2015/06/08 06:37:46 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <common.h>
#include <signal.h>

static void		wrong_usage(char *name)
{
	printf("Wrong usage, usage : %s <port>\n", name);
	exit(EXIT_FAILURE);
}

static void		create_master_socket(int *master_socket)
{
	int					opt;

	opt = TRUE;
	if (((*master_socket) = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		put_exit(2, "Socket failed", EXIT_FAILURE);
	if (setsockopt((*master_socket), SOL_SOCKET, SO_REUSEADDR,
				(char *)&opt, sizeof(opt)) < 0)
		put_exit(2, "Setsockopt", EXIT_FAILURE);
}

static void		bind_master_socket(int port, int master_socket,
	struct sockaddr_in addr)
{
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	if (bind(master_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		put_exit(2, "Bind failed", EXIT_FAILURE);
	printf("Listener on port %d\n", port);
	if (listen(master_socket, 3) < 0)
		put_exit(2, "Listen", EXIT_FAILURE);
}

static t_user	**init_users(void)
{
	t_user	**users;
	int		i;

	if (!(users = (t_user **)malloc(sizeof(t_user *))))
		put_exit(2, "Malloc error", EXIT_FAILURE);
	i = 0;
	while (i < MAX_CLIENTS)
	{
		if (!(users[i] = (t_user *)malloc(sizeof(t_user))))
			put_exit(2, "Malloc error", EXIT_FAILURE);
		users[i]->status |= ~S_IFCONNECTED;
		++i;
	}
	return (users);
}

int				main(int argc, char *argv[])
{
	struct sockaddr_in	addr;
	t_user				**users;
	int					client_sock[MAX_CLIENTS];
	int					master_socket;

	users = init_users();
	if (argc != 2)
		wrong_usage(argv[0]);
	signal(SIGPIPE, SIG_IGN);
	bzero(client_sock, sizeof(int) * (MAX_CLIENTS - 1));
	create_master_socket(&master_socket);
	bind_master_socket(atoi(argv[1]), master_socket, addr);
	printf("Waiting for connections ...\n");
	server_loop(master_socket, client_sock, addr, users);
	return (0);
}

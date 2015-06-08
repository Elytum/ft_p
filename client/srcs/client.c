/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 07:07:55 by achazal           #+#    #+#             */
/*   Updated: 2015/06/08 07:07:57 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <inputs.h>

void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit (-1);
}

int		create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Connect error with %s\n", addr);
		exit(2);
	}
	return (sock);
}

char	*call_inputs(char status)
{
	if (status == 1)
		return ("\x1b[32m➜\x1b[0m ft_p > ");
	else if (status == -1)
		return ("\x1b[31m➜\x1b[0m ft_p > ");
	else
		return ("➜ ft_p > ");
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;
	char				*str;
	char				status;

	status = 1;
	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);
	sock = create_client(av[1], port);
	// while ((str = ft_get_inputs("➜ ft_p > ")))
	while ((str = ft_get_inputs(call_inputs(status))))
	{
		printf("Sending %lu bytes\n", strlen(str));
		write(sock, str, strlen(str));
		write(sock, "\n", 1);
		free(str);
		status--;
		if (status == -2)
			status = 1;
	}
	close(sock);
}

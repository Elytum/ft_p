/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 05:49:07 by achazal           #+#    #+#             */
/*   Updated: 2015/06/08 05:49:10 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <config.h>

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/time.h>

typedef struct		s_user
{
	int				status;
	char			name[NAME_MAX];
	char			path[PATH_MAX];
	char			*input;
	int				socket;
	int				socket_id;
	time_t			timeout;
}					t_user;

# define S_IFCONNECTED 0b00000001
# define S_ISCONNECTED(u) (u & S_IFCONNECTED)

void	server_loop(int master_socket, int client_sock[MAX_CLIENTS],
	struct sockaddr_in addr, t_user **users);
void	create_user(t_user *user, char *name, int socket, int socket_id);

#endif
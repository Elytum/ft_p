/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 05:49:07 by achazal           #+#    #+#             */
/*   Updated: 2015/06/08 05:49:10 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <common.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <message.h>

static inline int	fill_socket_set(fd_set *readfds, int max_sd,
							int client_sock[MAX_CLIENTS])
{
	static int	sd;
	static int	i;

	i = 0;
	while (i < MAX_CLIENTS)
	{
		sd = client_sock[i];
		if (sd > 0)
			FD_SET(sd, readfds);
		if (sd > max_sd)
			max_sd = sd;
		++i;
	}
	return (max_sd);
}

static inline void	update_connexions_input(t_user *user, char buffer[BUFF_SIZE + 1],
	int valread, int sd)
{
	// char			*str;

	user->timeout = time(NULL) + LIFE_TIME;
	buffer[valread] = '\0';
	// printf("Updating with valread = %i\n", valread);
	if (user->message == NULL)
	{
		if (user->incoming_pos + valread <= HEADER_SIZE)
		{
			// printf("\tStep 0\n");
			memcpy(user->incoming + user->incoming_pos, buffer, valread);
			user->incoming_pos += valread;
			return ;
		}
		// printf("\tStep 1\n");
		// printf("Info : user->incoming_pos = %zu, valread = %d\n", user->incoming_pos, valread);
		if (user->incoming_pos != 0)
		{
			memcpy(user->incoming + user->incoming_pos, buffer, valread);
			user->incoming_pos += valread;
			user->message = ft_decode_message(user->incoming, user->incoming_pos);
		}
		else
			user->message = ft_decode_message(buffer, valread);
		// printf("User->message = %p\n", user->message);
		// printf("\tInfo : Len = %zu, Remaining = %zu\n\tContent = [", user->message->len, user->message->remaining);
	}
	else
	{
		// printf("\tStep 2\n");
		memcpy(user->message->content + (user->message->len - user->message->remaining), buffer, valread);
		user->message->remaining -= valread;
		// printf("User->message = %p\n", user->message);
		// printf("\tInfo : Len = %zu, Remaining = %zu\n\tContent = [", user->message->len, user->message->remaining);
	}
	if (user->message->remaining == 0)
	{
		// printf("User->message = %p\n", user->message);
		// printf("\tInfo : Len = %zu, Remaining = %zu\n\tContent = [", user->message->len, user->message->remaining);
		write(1, user->message->content, user->message->len);
		// printf("]\n");
		if (send(sd, user->message->content, user->message->len, 0) == -1)
			printf("Send failed\n");
		// printf("Part 1\n");
		printf("Received [%s] (len = %zu)\n", user->message->content, user->message->len);
		// printf("Part 2\n");
		free(user->message->content);
		// printf("Part 3\n");
		free(user->message);
		// printf("Part 4\n");
		user->message = NULL;
		// printf("Part 5\n");
		bzero(user->incoming, user->incoming_pos);
		user->incoming_pos = 0;
	}
}

static inline void	update_connexions(t_user **users, fd_set *readfds, struct sockaddr_in addr,
	int client_sock[MAX_CLIENTS])
{
	const int	len = sizeof(addr);
	static char	buffer[BUFF_SIZE + 1];
	int			valread;
	int			sd;
	int			i;

	bzero(buffer, BUFF_SIZE), i = 0;
	while (i < MAX_CLIENTS)
	{
		sd = client_sock[i];
		if (FD_ISSET(sd, readfds))
		{
			if ((valread = read(sd, buffer, BUFF_SIZE)) == 0)
			{
				getpeername(sd, (struct sockaddr *)&addr, (socklen_t *)&len);
				printf("Client disconnected, ip %s, port %d\n",
						inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
				close(sd);
				client_sock[i] = 0;
			}
			else
				update_connexions_input(users[i], buffer, valread, sd);
		}
		++i;
	}
}

static inline void	new_connexions(int master_socket, struct sockaddr_in addr,
	int client_sock[MAX_CLIENTS], t_user **users)
{
	const int	addrlen = sizeof(addr);
	int			i;
	int			new_socket;

	if ((new_socket = accept(master_socket, (struct sockaddr *)&addr,
					(socklen_t*)&addrlen)) < 0)
		put_exit(2, "Accept", EXIT_FAILURE);
	printf("New connection, socket fd is %d, ip is : %s, port : %d \n",
		new_socket, inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
	if (send(new_socket, WELCOME_MESSAGE, WELCOME_MESSAGE_LEN, 0) !=
			WELCOME_MESSAGE_LEN)
		printf("Send\n");
	printf("Welcome message sent successfully\n");
	i = 0;
	while (i < MAX_CLIENTS)
	{
		if (client_sock[i] == 0)
		{
			client_sock[i] = new_socket;
			printf("Adding to list of sockets as %d\n", i);
			create_user(users[i], "unknown", new_socket, i);
			return ;
		}
		++i;
	}
}

void					update_server(t_user **users, int client_sock[MAX_CLIENTS])
{
	int					i;
	int					sd;
	time_t				actual_time;
	struct sockaddr_in	addr;
	const int			len = sizeof(addr);

	i = 0;
	actual_time = time(NULL);
	while (i < MAX_CLIENTS)
	{
		if (S_ISCONNECTED(users[i]->status))
		{
			if (users[i]->timeout <= actual_time)
			{
				sd = client_sock[users[i]->socket_id];
				getpeername(sd, (struct sockaddr *)&addr, (socklen_t *)&len);
				printf("Client timeout, ip %s, port %d\n",
				inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
				close(sd);
				client_sock[users[i]->socket_id] = 0;
				users[i]->status |= ~S_IFCONNECTED;
			}
			else
			{
				printf("User connected with socket %i and name %s\n",
					users[i]->socket, users[i]->name);
			}
		}
		++i;
	}
}

void				server_loop(int master_socket, int client_sock[MAX_CLIENTS],
	struct sockaddr_in addr, t_user **users)
{
	int			activity;
	int			max_sd;
	fd_set		readfds;

	while (TRUE)
	{
		FD_ZERO(&readfds);
		FD_SET(master_socket, &readfds);
		max_sd = fill_socket_set(&readfds, master_socket, client_sock);
		activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
		if ((activity < 0) && (errno != EINTR))
			printf("Select error\n");
		if (FD_ISSET(master_socket, &readfds))
			new_connexions(master_socket, addr, client_sock, users);
		update_connexions(users, &readfds, addr, client_sock);
		update_server(users, client_sock);
	}
}

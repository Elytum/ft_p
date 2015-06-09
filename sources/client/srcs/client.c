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
#include <message.h>
#include <config.h>

void	usage(char *str)
{
	printf("Usage: %s <ip> <port>\n", str);
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
		printf("Connect error with %s with port %i\n", addr, port);
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
	int					sock;
	char				*str;
	char				status;
	char				*coded;

	status = 1;
	if (ac != 3)
		usage(av[0]);
	if (strcmp(av[1], "localhost") == 0)
		sock = create_client("127.0.0.1", atoi(av[2]));
	else
		sock = create_client(av[1], atoi(av[2]));
	while ((str = ft_get_inputs(call_inputs(status))))
	{
		printf("Sending %lu bytes\n", strlen(str));
		// write(sock, str, strlen(str));
		// write(sock, "\n", 1);
		ft_code_message(0, str, strlen(str), &coded);
		free(str);
		write(sock, coded, strlen(str) + HEADER_SIZE);
		write(sock, "\n", 1);
		free(coded);
		status--;
		if (status == -2)
			status = 1;
	}
	close(sock);
}

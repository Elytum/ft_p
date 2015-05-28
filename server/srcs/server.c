#include <common.h>
#include <server.h>

static void		usage(const char *str, const int op)
{
	ft_putendl(str);
	(void)op;
	exit(-1);	
}

static int		server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (!(proto = getprotobyname("tcp")))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (!(bind(sock, (const struct sockaddr *)&sin, sizeof(sin))))
		usage("bind", 2);
	listen(sock, 42);
	return (sock);
}

int		main(int ac, char **av)
{
	int		sock;

	if (ac != 2)
		usage(av[0], 0);
	if (str_issort(av[1]))
		sock = create_server(ft_atoi(av[1]));
	else
		usage(av[1], 1);
	launch_server();
	cs = accept(sock, );
	close(sock);
	return (0);
}

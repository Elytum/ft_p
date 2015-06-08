
#include <server.h>
#include <config.h>

void	ft_cpymax(char *dst, const char *src, size_t max)
{
	while (--max && *src)
		*dst++ = *src++;
	*dst = '\0';
}

void	create_user(t_user *user, char *name, int socket, int socket_id)
{
	user->status |= S_IFCONNECTED;
	ft_cpymax(user->name, name, NAME_MAX);
	user->socket = socket;
	user->socket_id = socket_id;
	user->timeout = time(NULL) + LIFE_TIME;
}
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void		put_exit(int stream, char *str, int out)
{
	write(stream, str, strlen(str));
	write(stream, "\n", 1);
	exit(out);
}
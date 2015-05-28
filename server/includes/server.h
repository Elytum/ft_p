#ifndef SERVER_H
# define SERVER_H

#include <common.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int			launch_server(int sock);

#endif

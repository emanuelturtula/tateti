#ifndef __SOCKETS_H__
#define __SOCKETS_H__

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <netdb.h> 

#include "types.h"

status_t tcp_connect(char* ip, size_t port, int* sockfd);

#endif
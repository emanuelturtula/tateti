#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "types.h"

void send_heartbeat_message(int sockfd);
status_t send_login_message(int sockfd, char *player_name, char** response);


#endif
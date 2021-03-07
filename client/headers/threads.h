#ifndef __THREADS_H__
#define __THREADS_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h> 

#include "types.h"

status_t create_heartbeat_thread(pthread_t *tid, int sockfd);

#endif
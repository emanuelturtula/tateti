#include "../headers/threads.h"

void *send_heartbeat_thread(void *sockfd_ptr);

void *send_heartbeat_thread(void *sockfd_ptr)
{
    int sockfd = *((int *)sockfd_ptr);
    free(sockfd_ptr);
    while(1)
    {
        send_heartbeat_message(sockfd);
        sleep(1);
    }
    return NULL;
}

status_t create_heartbeat_thread(int sockfd, pthread_t *tid) 
{
    pthread_t t;
    int *sockfd_ptr = malloc(sizeof(*sockfd_ptr));
    if (sockfd_ptr == NULL) 
        return ERROR_INSUFFICIENT_MEMORY;
    *sockfd_ptr = sockfd;
    if (tid == NULL)
        pthread_create(&t, NULL, send_heartbeat_thread, sockfd_ptr);
    else
        pthread_create(tid, NULL, send_heartbeat_thread, sockfd_ptr);
        
    return OK;
}
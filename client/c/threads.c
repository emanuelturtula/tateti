#include "../headers/threads.h"

void *send_heartbeat(void *sockfd_ptr);

void *send_heartbeat(void *sockfd_ptr)
{
    char message[] = "HEARTBEAT \r\n \r\n";
    int sockfd = *((int *)sockfd_ptr);
    free(sockfd_ptr);
    while(1)
    {
        write(sockfd, message, strlen(message));
        sleep(1);
    }
    return NULL;
}

status_t create_heartbeat_thread(pthread_t *tid, int sockfd) 
{
    int *sockfd_ptr = malloc(sizeof(*sockfd_ptr));
    if (sockfd_ptr == NULL) 
        return ERROR_INSUFFICIENT_MEMORY;
    *sockfd_ptr = sockfd;
    pthread_create(tid, NULL, send_heartbeat, sockfd_ptr);
    return OK;
}
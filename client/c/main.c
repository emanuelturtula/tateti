#include "../headers/main.h"

int main()
{
    status_t status;
    pthread_t heartbeat_thread;
    int sockfd = 0;
    if ((status = tcp_connect("127.0.0.1", TCP_PORT, &sockfd)) != OK)
        return status;

    if ((status = create_heartbeat_thread(&heartbeat_thread, sockfd)) != OK)
        return status;
    sleep(3);
    close(sockfd);
    return EXIT_SUCCESS;
}
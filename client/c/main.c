#include "../headers/main.h"

int main()
{
    status_t status;
    pthread_t heartbeat_thread;
    char* player_name = "Ema";
    char* response = malloc(sizeof(*response));
    int sockfd = 0;
    if ((status = tcp_connect("127.0.0.1", TCP_PORT, &sockfd)) != OK)
        return status;
    if ((status = create_heartbeat_thread(sockfd, &heartbeat_thread)) != OK)
        return status;
    status = send_login_message(sockfd, player_name, &response);
    close(sockfd);
    return EXIT_SUCCESS;
}

#include "../headers/messages.h"

void send_heartbeat_message(int sockfd)
{
    const char *message = "HEARTBEAT \r\n \r\n";
    write(sockfd, message, strlen(message));
}

status_t send_login_message(int sockfd, char *player_name, char** response)
{
    char message[80] = {0};
    char buffer[80] = {0};
    sprintf(message, "LOGIN|%s \r\n \r\n", player_name);
    write(sockfd, message, strlen(message));
    read(sockfd, buffer, sizeof(buffer));
    *response = &buffer[0];
    return OK;
}
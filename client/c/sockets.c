#include "../headers/sockets.h"

status_t tcp_connect(char* ip, size_t port, int* sockfd)
{
    if (ip == NULL || sockfd == NULL)
        return ERROR_NULL_POINTER;
    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr(ip); 
    servaddr.sin_port = htons(port); 

    if (((*sockfd) = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return ERROR_SOCKET_CREATION;
    
    if (connect((*sockfd), (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        close((*sockfd));
        return ERROR_SOCKET_CONNECTION;
    }
        
    return OK;
}
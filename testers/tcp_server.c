#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 
#define MAX 80 
#define PORT 2000 
#define SA struct sockaddr 

#define COUNT_HEARTBEAT 5

// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
	char buff[MAX]; 
	char message[] = "200|OK \r\n \r\n";
	int n; 
	size_t heartbeat_received = 0;
	// infinite loop for chat 
	while (1) { 
		bzero(buff, MAX); 
		// read the message from client and copy it in buffer 
		read(sockfd, buff, sizeof(buff)); 
		// print buffer which contains the client contents 
		if (strcmp(buff, "HEARTBEAT \r\n \r\n") == 0)
        {
			printf("From client: %s\n", buff);
            printf("Received heartbeat\n");
        }
		if (strcmp(buff, "LOGIN|Ema \r\n \r\n") == 0)
		{
			printf("From client: %s\n", buff);
            printf("Login Ema\n");
			write(sockfd, message, sizeof(message));
		}
	} 
} 

// Driver function 
int main() 
{ 
	int sockfd, connfd;
    socklen_t len; 
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n"); 

	// Now server is ready to listen and verification 
	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli); 

	// Accept the data packet from client and verification 
	connfd = accept(sockfd, (SA*)&cli, &len); 
	if (connfd < 0) { 
		printf("server acccept failed...\n"); 
		exit(0); 
	} 
	else
		printf("server acccept the client...\n"); 

	// Function for chatting between client and server 
	func(connfd); 

	// After chatting close the socket 
	close(sockfd); 
} 

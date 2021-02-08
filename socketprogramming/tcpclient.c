//this is tcp client
//function to use:: socket, connect, read, write , close

// this client will sent content to the server and then read the content 

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

#define MAX_LINE 100

int main()
{
	int sockfd, clilen;
	struct sockaddr_in servaddr;
	char buff[MAX_LINE];
	
	//make a socket
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	//prepare address for server
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1229);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); ///localhost 127.0.0.1
	
	//connect to this server
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	//printf("client is ready for the connection.....\n");
	printf("\nSay sthg to the server:: ");
	scanf("%[^\n]", buff);
	//write request to the server
	write(sockfd, buff, 20);
	read(sockfd, buff, MAX_LINE);
	
	printf("msg from server:: %s\n", buff);
 
	close(sockfd);
	return 0;
}


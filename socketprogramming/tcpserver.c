//this is tcp server
//function to use:: socket, listen, bind, accept, read, write , close

// this server will receive content from client , displays on console and write a content back to client

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
	int sockfd, connfd, clilen;
	struct sockaddr_in servaddr, cliaddr;
	char buff[MAX_LINE];
	
	//make a socket
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	//prepare address for this socket
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1229);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); ///localhost 127.0.0.1
	
	
	//bind this address to the socket
	bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	//make this socket passive listening socket
	listen(sockfd, 5);
	
	
	printf("server is ready for the connection.....\n");
	//accept the incoming connection request 
	//----now use connfd
	while(1)
	{
		connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
	
		read(connfd, buff, MAX_LINE);
		printf("\nClient Says:: %s", buff);
		
		write(connfd, "Thank you...", 16);	
		
	}
	close(connfd);
	close(sockfd);
	
	return 0;
}


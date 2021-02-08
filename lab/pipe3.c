#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#define MSGSIZE 50 
char* msg1 = "hello, Network Programmers!!"; 
char* msg2 = "Bikash Shrestha"; 
 

void client(int fdr, int fdw)
{
	int fd;
	char buff[100];
	//read from IPC channel
	
}
void server() 
{

}

  
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], i; 
    int p1[2], p2[2], pid;
    
    pid = fork();
    
  
    if (pipe(p) < 0) 
        exit(1); 
  	
    if(pid==0)
    {
    	close(pipe1[1]);
    	close(pipe2[0]);
    	client(pipe1[0], pipe2[1]);
    	return 0;
    }
    else
    {
    	printf("\nParent\n");
    	close(pipe1[0]);
    	close(pipe2[1]);
    	server(pipe1[1], pipe2[0]);
    }
  	
    printf("\n\nexit\n\n");
    return 0; 
}

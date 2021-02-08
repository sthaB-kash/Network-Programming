#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#define MAXLINE 100

void server(int fdr,int fdw)
{
	int fd;
	size_t len;
	size_t n;
	char buff[100];
	
	//read from IPC channel
	if((fd= open(buff,O_RDONLY)) <0){
	sprintf(buff+n,sizeof(buff)-n,': can't open, %s',strerror(errno));
	n=strlen(buff);
	write(fdw,buff,n);
	}
	else{
	while ( (n=Read(fd, buff, MAXLINE)) > 0)
		write(fdw,buff,n);
	close(fd);
	}
}

void client(int fdr,int fdw)
{
	int fd;
	size_t len;
	size_t n;
	char buff[100];
	
	//read from IPC channel
	if((fd= open(buff,O_RDONLY)) <0){
	sprintf(buff+n,sizeof(buff)-n,': can't open, %s',strerror(errno));
	n=strlen(buff);
	write(fdw,buff,n);
	}
	else{
	while ( (n=Read(fd, buff, MAXLINE)) > 0)
		write(fdw,buff,n);
	close(fd);
	}
}

int main()
{
	int pipe1[2],pipe2[2];
	
	int pid;
	
	pid=fork();
	
	if(pid==0)//child process
	{
		close(pipe1[1]);
		close(pipe2[0]);
		waitpid(pid, NULL, 0);
		server(pipe1[0],pipe2[1]);
		return 0;
	}

	// parent process
	close(pipe1[0]);
	close(pipe2[1]);
	client(pipe1[1],pipe2[0]);

	waitpid(pid,NULL,0);//wait for child to terminate
	return 0;	
}







#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

char * msg = "hello bikash";
char op[16];

int main()
{
	int pid, fd[2];
	char *buff;
	pipe(fd);
	//printf("pipe created\n\n");
	pid=fork();
	if(pid<0)
	{
		printf("Error occurred");
		exit(0);
	}
	else if(pid==0)
	{
		write(fd[1], msg, 14);
		printf("written\n");
	}
	else
	{
		//sleep(5);
		read(fd[0], buff, 16);
	//	read(fd[0], buff, 2);
	
		printf("Received-1: %s\n", buff);
	//	printf("Received-2: %s\n", op);
	}
	
	return 0;
}

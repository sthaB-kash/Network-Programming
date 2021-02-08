#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h> 

pid_t Fork(void);

int main() {

	int pid;
	char bikash[16] = "BIKASH SHRESTHA";
	printf("\n\n\n\n\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<%s>>>>>>>>>>>>>>>>>>>>>>>>>>\n",bikash);
	pid = Fork();
	
	
	//checking process
	if(pid==0)
	{
		printf("\n\nHello, I'm child executing from '%s' terminal\n", bikash);
		printf("MY id=%d, my parent id= %d and my child = %d\n\n", getpid(), getppid(), pid);
		printf("\n------------------------------end--------------------------------\n\n\n\n\n");
	}
	else 
	{
		printf("\n\nHello, I'm parent executing from '%s' terminal\n", bikash);
		printf("id= %d ,pid=%d, child=%d\n", getpid(), getppid(), pid);
	}
	
	return 0;
}

pid_t Fork()
{
	int pid=fork();
	if(pid==-1)
	{
		printf("\nthere is error while calling fork.");
		exit(-1);
	}
	return pid;
}

#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		printf("child::%d", pid);
	}
	else
		printf("print::%d",pid);
		
	return 0;		
}

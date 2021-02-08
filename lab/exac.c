#include<stdio.h>
#include<unistd.h>


int main()
{
	printf("\nbefore executing exect\n");
	
	execl("~/Desktop/myscript.sh", "myscript", (char *) 0);
	
	printf("\nafter exec  call\n");
	
	return 0;
}

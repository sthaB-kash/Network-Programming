#include<stdio.h>
#include<unistd.h>


int Exacl()
{
	int val = execl("/bin/ls","ls", (char *) 0);
	
	return val;
}

int main()
{
	int val;
	printf("\nbefore executing exect\n");
	
//	val = Exacl();
	execl("/bin/ls","ls", (char *) 0);
	printf("\n%d\n", val);
	
	printf("\nafter exec  call\n");
	
	return 0;
}

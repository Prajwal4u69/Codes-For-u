#include<stdio.h>
#include<signal.h>
int main()
{
	int a,x;
	a=fork();
	if(a==0)
	{
		while(1)
		printf("child executing \n");
		
	}
	else
	{	printf("Child Id %d\n",a);
		sleep(2);//to display that child is executing
		kill(a,SIGQUIT);
		printf("child ID %d \n",a);
	}
}

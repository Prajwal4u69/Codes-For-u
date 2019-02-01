#include<stdio.h>
int main()
{
	int a,x;
	a=fork();
	if(a==0)
	{
			
			printf("child executed\n");
	}
	else
	{	sleep(3);
		x=wait(0);
		printf("parent woke child ID returned by fork  %d  Child ID returned by WAIT%d\n",a,x);
	}
}

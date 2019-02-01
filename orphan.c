#include<stdio.h>
int main()
{
	int a;
	a=fork();
	if(a==0)
	{
			sleep(3);
			printf("child\n");
	}
	else
	printf("parent terminated\n");
}

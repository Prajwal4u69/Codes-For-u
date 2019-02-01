#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
int main()
{
	int a;
	a=fork();
	if(a==0)	
	printf("child\n");
	else
	printf("parent\n");
}



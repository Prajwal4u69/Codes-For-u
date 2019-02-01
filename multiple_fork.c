#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
int main()
{
	int x,y,z;
	printf("\nroot id %d\n",getpid());
	x=fork();
	y=fork();
	z=fork();
	
	if(x>0&&y>0&&z>0)
	{
	        printf("\nwe are in root process %d child 1 %d child 2 %d child 3 %d\n",getpid(),x,y,z);        
	}
	else if(x>0&&y>0&&z==0)
	{
	        printf("\nchild %d of root %d ",getpid(),getppid());        
	}
	else if(x>0&&y==0&&z>0)
	{
	        printf("\nchild %d of root %d\n",getpid(),getppid());        
	}
	else if(x==0&&y>0&&z>0)
	{
	        printf("\nchild %d of root %d\n",getpid(),getppid());        
	}
	else if(x==0&&y==0&&z>0)
	{
	        printf("\nchild %d of child 1 of root %d\n",getpid(),getppid());        
	}
	else if(x==0&&y>0&&z==0)
	{
	        printf("\nchild %d of child 1 of root %d \n",getpid(),getppid());        
	}
	else if(x==0&&y==0&&z==0)
	{
	        printf("\nchild %d of child of child 1 of root %d\n",getpid(),getppid());        
	}
	else if(x>0&&y==0&&z==0)
	{
	        printf("\nchild %d of child 2 of root %d \n",getpid(),getppid());        
	}
	
	
}



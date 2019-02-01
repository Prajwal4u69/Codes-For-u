#include<stdio.h>
#include<malloc.h>

void main()
{
int *p1,*p2,*p3,n1,n2,n3;


printf("\nenter the limit if array 1,2,3");

    scanf("%d%d%d",&n1,&n2,&n3);
    fun(&p1,&n1);




    fun(&p2,&n2);



    fun(&p3,&n3);







}


void fun(int *p,int n)
{
int i;
p=(int*)malloc(sizeof(int));

if(p==NULL)
printf("\nno memory is allocated");
else

printf("\nenter the elements in the array");
for(i=0;i<n;i++)
{
scanf("%d",p+i);
}

for(i=n-1;i>=0;i--)
{
printf(" %d",*(p+i));
}


}

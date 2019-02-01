#include<stdio.h>
void main()
{

int a[100],i,n,r;

printf("\nenter the limit of an array");
scanf("%d",&n);

printf("\nenter the rotation performend on the array");
scanf("%d",&r);

printf("\nenterthe elements in the array");
for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }


int j;
int temp;

for(i=0,j=(n-r);i<j;i++,j--)
{
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;

}

for(i=(n-r+1),j=n-1;i<j;i++,j--)
{
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;

}
for(i=1,j=n-1;i<j;i++,j--)
{
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;

}

    for(i=0;i<n;i++)
    {
        printf(" %d",a[i]);
    }



}

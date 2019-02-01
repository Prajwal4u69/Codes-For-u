#include<stdio.h>
#include<math.h>

void main()
{
int i,itr;
float a,b,q,r,c;

 printf("\nEnter the value of a and b");
 scanf("%f%f",&a,&b);

 printf("\nEnter the approximation");
 scanf("%d",&itr);
q=a-cos(a);
 r=b-cos(b);

do
 {
    c=((a*r)-(b*q));
    c=c/(q-r);
 //printf("\n%f  ",c);
    q=a-cos(a);
    r=c-cos(c);

    if(q*r < 0)
    {
        printf("\n%f  ",a);

        b=c;
    }
    else
    {
        a=c;
        printf("\n%f  ",a);
    }

 itr--;
 }while(itr!=1);
printf("\n%f  ",a);
}

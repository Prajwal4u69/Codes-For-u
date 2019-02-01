#include<stdio.h>
#define MAX 10

int insert(int a[],int r, int f);
int del(int a[],int r,int f);
void display(int a[],int r, int f);

void main()
{
 int a[MAX];
 int ch,n,r=-1,f=-1;
 do
    {
    printf(" \n1.insert\n2,del\n3.display\n4.exitt");
    printf("\nenter your choice");
    scanf("%d",&ch);

     switch(ch)
        {
         case 1:
         r=insert(a,r,f);
         if(f==-1)
         {
         f=0;
         }
        break;

         case 2:
         f=del(a,r,f);
         if(f==-1)
         {
         r=-1;
         }
         break;

        case 3:
        display(a,r,f);
        break;

        case 4:
        break;
        default: printf("\ninvalid option");


        }

    }while(ch!=4);

}
int insert(int a[],int r,int f)

{
int x;
printf("\nenter ther value");
scanf("%d",&x);

    if((r==MAX-1 && f==0) || (f==r+1))
    {
    printf("overflow");
    }
    else
        {
            if(f>0 && r==MAX-1)
            {
            r=0;
            a[r]=x;
            }
                else
                {
                r++;
                a[r]=x;
                }
        }

return(r);

}

int del(int a[],int r,int f)
{
    if(f==-1)
    {
    printf("\nno elements are present");
    }
    else
        if(f==r)
          {
          printf("\ndeleted value %d",a[f]);
          f=-1;
          }
    else
        {
            printf("\ndeleted value %d",a[f]);
            f++;
                if(f==MAX)
                {
                f=0;
                }
        }
 return(f);
}

void display(int a[], int r, int f)
{
 /*  int i;

        if(f==-1)
            printf("queue is empty");


  if(f==r)
  {
  printf("%d",a[f]);
  }
  else

    if(f<r)



        for(i=f;i<=r;i++)
        {

        printf(" %d",a[i]);
        }
        else
        {
             if(f>r)



        for(i=r;i<=r;i++)
        {

        printf(" %d",a[i]);
        }


        }
*/

            if(f!=-1)
            {
                int i;
                for(i=f;i!=r;i=(i+1)%MAX)
                {
                    printf(" %d",a[i]);
                }
            }
                else
                    printf("\ncqueue is empty");
            }





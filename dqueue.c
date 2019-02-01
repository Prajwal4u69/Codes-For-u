#include<stdio.h>
#define MAX 10


int insert(int dqueue[],int r,int x);
int delfront(int dqueue[],int f,int r);
int delend(int dqueue[],int r,int f);
void display(int dqueue[],int r,int f);


int main()
{
    int ch,r=-1,f=-1,x,dqueue[MAX];
do
    {
     printf("\n1.insert\n2.deletefront\n3.delete end\n4.display");
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:
     scanf("%d",&x);
     r=insert(dqueue,r,x);
     if(r==0)
     {
     f=0;
     }
     break;

     case 2:
     f=delfront(dqueue,f,r);
     if(f==-1)
     r=-1;
     break;

     case 3:
     r=delend(dqueue,r,f);
     if(r==-1)
     {
     f=-1;
     }
     break;
     case 4:
     display(dqueue,r,f);
     break;

     case 5:
     break;
     default:
     printf("invalid option");
     }


    }while(ch!=5);

return(0);
}

int insert(int dqueue[],int r,int x)
{

if(r==MAX-1)
    printf("\noverflow");
    else
    {
        if(r==-1)
            {
                r=r+1;
                dqueue[r]=x;
            }
            else
            {
             r=r+1;
            dqueue[r]=x;

            }


    }
return(r);
}

int delfront(int dqueue[],int f,int r)
{
    if(f==-1)
    printf("underflow");
    else
    {
        if(f==(r+1))
        {
        f=-1;
        }
        else
            {
            printf("%d",dqueue[f]);
            f=f+1;

            }


    }

if(f==MAX)
f=-1;
return(f);

}

int delend(int dqueue[],int r,int f)
{
    if(r==-1)
    printf("underfow");
    else
        {
            if(r==(f-1))
            {
            r=-1;
            }
                else
                    {
                        printf("%d",dqueue[r]);
                        r=r-1;
                    }





        }

return(r);
}

void display(int dqueue[],int r,int f)
{
int i;
if(f<=r)
for(i=f;i<=r;i++)
{
printf(" %d",dqueue[i]);
}
else
printf("\nqueue is empty");


}

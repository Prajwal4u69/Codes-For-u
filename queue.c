#include<stdio.h>
#define MAX 10

int insert(int queue[],int r,int x);
int delete(int queue[],int f);
void display(int queue[],int f,int r);

int main()
{
int f=-1,r=-1,queue[MAX],ch,x;
 do
    {
    printf("\n1.insert\n2.delete\n3.display");
    scanf("%d",&ch);

        switch(ch)
        {
        case 1:
        printf("\nenter the value");
        scanf("%d",&x);
        r=insert(queue,r,x);
        if(f==-1)
        {
        f=0;
        }
        break;

        case 2:
        f=delete(queue,f);
        if(f==-1)
        {
        r=-1;
        }
        break;

        case 3:
        display(queue,f,r);
        break;

        case 4:
        break;
        default: printf("\ninvalid option");


        }
    }while(ch!=4);
    return(0);
}
int insert(int queue[],int r,int x)
{
    if(r==MAX-1)
    {
    printf("\noverflow");
    }
    else
        {
        if(r==-1)
        {
        r=r+1;
        queue[r]=x;
        }
            else
                {
                r=r+1;
                queue[r]=x;

                }
        }

return(r);
}

int delete(int queue[],int f)
{
    if(f==-1)
    {
    printf("\nunderflow");
    }
    else
        {
        printf("\ndeleted element %d",queue[f]);
        f++;

        }
    if(f==MAX)
    f=-1;

return(f);

}

void display(int queue[],int f,int r)
{
int i;
    if(f==-1)
    printf("queue is empty");

    else
        {
        for(i=f;i<=r;i++)
        printf(" %d",queue[i]);
        }




}






#include<stdio.h>
#define MAX 10

int main()
{
 int ch,f=-1,r=-1,dqueue[MAX],x;

  do
    {
    printf("\n1.insert front \n2.insert rear\n3.delete front\n4.dislpay");
    scanf("%d",&ch);
        switch(ch)
        {
        case 1:  scanf("%d",&x);
                 f=finsert(dqueue,f,x);
                 if(r==-1)
                 r=0;
                 break;
        case 2:  scanf("%d",&x);
                 r=rinsert(dqueue,r,x);
                 if(f==-1)
                 f=0;
                 break;

        case 3:  f=delete(dqueue,f);
                 if(f>r)
                 f=-1;
                 r=-1;
                 break;

        case 4:  display(dqueue,f,r);
                 break;

        case 5:  break;
                default: printf("\ninvalid option");



        }
    }while(ch!=5);
return(0);
}

int finsert(int dqueue[],int f,int x)
{
    if(f==-1)
    dqueue[++f]=x;
    else
    if(f>0)
    dqueue[--f]=x;

    else
    {
    printf("cannot insert element at front");
    }

return(f);


}

int rinsert(int dqueue[],int r,int x)
{
    if(r==MAX-1)
        printf("\nqueue is full");
    else
       dqueue[++r]=x;

return(r);

}

int delete(int dqueue[],int f)
{
    if(f==-1)
    printf("\nqueue is empty");
    else
    {
    printf("\ndeleted value %d",dqueue[f++]);

    }

    return(f);


}
void display(int dqueue[],int f,int r)
    {
       if(f==-1)
       printf("\nqueue is empty");
       else
       for(;f<=r;f++)
       {


       printf("%d",dqueue[f++]);

       }


    }

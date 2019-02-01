#include<stdio.h>
#define MAX 10

int push(int stack[],int top,int x);
int pop(int stack[],int top);
void display(int stack[],int top);
void peep(int top);
void empty(int top);
void full(int top);


void main()
{
 int stack[MAX],top=-1,x,ch;
    do
    {
    printf("\n1.push\n2.pop\n3.display\n4.peep\n5.empty\n6.full");
    scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        printf("\nenter the value");
        scanf("%d",&x);
        top=push(stack,top,x);
        break;

        case 2:
        top=pop(stack,top);
        break;


        case 3:
        display(stack,top);
        break;

        case 4:
        peep(top);
        break;

        case 5:
        empty(top);
        break;

        case 6:
        full(top);
        break;

        case 7:
        break;
        default: printf("\ninvalid option");

        }

    }while(ch!=7);

}

int push(int stack[],int top,int x)
 {
    if(top==MAX-1)
    printf("\noverflow");
    else
    {
        top++;
        stack[top]=x;
    }
        return(top);
 }

 int pop(int stack[],int top)
 {
  if(top==-1)
  printf("\nunder flow");

  else
    {
    printf("\n %d",stack[top]);
    top--;
    }
 return(top);
 }

void display(int stack[],int top)
{
    int i;

    if(top==-1)
    printf("\nNo elements to display");
    else
        {
       for(i=0;i<=top;i++)
        printf(" %d",stack[i]);

        }
}

void peep(int top)
{
printf("\n%d",top);

}
void empty(int top)
{
if(top==-1)
printf("\nempty");
else
printf("\nnot empty");
}
void full(int top)
{
if(top==MAX-1)
printf("\nstack is full");
else
printf("\n \nstack is not full");
}

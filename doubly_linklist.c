#include<stdio.h>
#include<malloc.h>


typedef struct queue
{
struct queue *prev;
int data;
struct queue *next;



}node;

void insert(node **left,node **right)
{
node *p=NULL;

p=(node*)malloc(sizeof(node));

if(p!=NULL)
{
printf("\nenter the number");
scanf("%d",&(p->data));

int ch;


if(*left==NULL)
{
*left=p;
*right=p;

(*left)->prev=NULL;
(*right)->next=NULL;
}
else
{
printf("1.front\n2.end\n3between");
scanf("%d",&ch);

if(ch==1)
{
p->prev=NULL;
p->next=*left;
(*left)->prev=p;
*left=p;
}

if(ch==2)
{
p->prev=*right;
(*right)->next=p;
p->next=NULL;
*right=p;
}

if(ch==3)
{
int num;
printf("\nuser enter the number after which you want to add input no");
scanf("%d",&num);
node *a=*left;
while(a->data!=num)
{
a=a->next;
}

p->prev=a;
p->next=a->next;

a->next->prev=p;
a->next=p;

}

}}
else
printf("no memory is aloocated");




}
void delete(node **left,node **right)
{
    if(*left!=NULL)
    {


    int num;
    printf("\enter the no you want to delete ");
    scanf("%d",&num);

    if((*left)->data==num)
    {
        *left=(*left)->next;
        (*left)->prev=NULL;
    }
    else{

    node *b=*left,*a=(*left)->next;
    while(a->data!=num)
    {
        b=b->next;
        a=a->next;
    }
    if(a->next==NULL)
    {
        b->next=NULL;
    free(a);
    }
    else{

        b->next=a->next;
        a->next->prev=b;


    }
    }


    }else
    printf("no node is present");
}
void display(node *left,node *right)
{
    if(left !=NULL)
    {


    while(left!=NULL)
    {

        printf(" %d",(left)->data);
        left=left->next;
    }


    }
    else
        printf("\nno node is present");

}
  node * reverse(node*top)
  {
      node *p,*q;

      if(top==NULL)
        return;

      p=top;
      q=p->next;

      if(q==NULL)
        return(p);

      q=reverse(q);

      p->next->next=p;
      p->next=NULL;

      return(q);



 }

void main()
{
node *left=NULL,*right=NULL;
int ch;
do
{
printf("\n1insert\n2delete\n3display\n4reverse");
scanf("%d",&ch);

switch(ch)
{
case 1:
insert(&left,&right);
break;

case 2:
delete(&left,&right);
break;
case 3:
display(left,right);
break;

case 4:left=reverse(left);
break;
case 5:
default:printf("invalid choice");
break;




}

}while(ch!=5);


}


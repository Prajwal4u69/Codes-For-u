#include<stdio.h>
#include<malloc.h>

    typedef struct queue
    {
    int info;
    struct queue *next;
    }node;


 
   

    void push(node **rear,node **front)
    {
    node *p=NULL;

    p=(node*)malloc(sizeof(node));

    if(p==NULL)
    printf("\nNo memory is aloocated f0r the node");

    else
        {
         printf("\nenter the number");
         scanf("%d",&p->info);

         p->next=NULL;
         if(*rear!=NULL)
         {
         (*rear)->next=p;

         }
         (*rear)=p;

        }
        if(*front==NULL)
        (*front)=(*rear);
    }

   void serve(node **front,node **rear)
   {

   node *temp=*front;

    if(*front==NULL)

    printf("\nno address to be returned");


    else
    {
    printf("\ndeleted value %d",temp->info);
 (*front)=(*front)->next;
   free(temp);

    }
if(*front==NULL)
{
*rear=NULL;   
}

   }

   void display(node *rear,node *front)

   {
   if((front)==NULL)
   printf("\nNo node get formed");

   else
   {

   while(front!=NULL)
   {
   printf(" %d",front->info);
   front=front->next;

   }
   }

   }

  


   void main()

   {
   node *front=NULL,*rear=NULL;
   int ch;

   do
   {
   printf("\n1.uinsert\n2.delete\n3.display");
   scanf("%d",&ch);

   switch(ch)
   {
   case 1:push(&rear,&front);
          
          break;

   case 2:serve(&front,&rear);
          
          break;

   case 3:display(rear,front);
          break;

   
    case 4:break;
           default: printf("invalid option");
   }
   }while(ch!=4);


   }

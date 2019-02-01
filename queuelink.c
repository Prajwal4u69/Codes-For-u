#include<stdio.h>
#include<malloc.h>

    typedef struct queue
    {
    int info;
    struct queue *next;
    }node;


    void del_between(node*front)
    {
        node *p,*q;

        p=front;
        q=p->next;

        if(front==NULL)
            printf("\nno node is present");
        else{

                int num;

            printf("\nenter the number you want to delete");
            scanf("%d",&num);

            while(q->info!=num)
            {
                q=q->next;
                p=p->next;
            }

            p->next=q->next;
            free(q);


        }
    }

    node * push(node * rear)
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
         if(rear!=NULL)
         {
         rear->next=p;

         }
         rear=p;

        }
        return(rear);
    }

   node * serve(node * front)
   {

   node *temp=front;

    if(front==NULL)

    printf("\nno address to be returned");


    else
    {
    printf("\ndeleted value %d",temp->info);
 front=front->next;
   free(temp);

    }
   return(front);

   }

   void display(node * rear,node * front)

   {
   if(front==NULL)
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

   void count(node * rear ,node * front)
   {
       int c=0;

        while(front!=NULL)
        {
            c++;
            front=front->next;
        }
        printf("\n no of nodes are %d",c);

        }




   void main()

   {
   node *front=NULL,*rear=NULL;
   int ch;

   do
   {
   printf("\n1.uinsert\n2.delete\n3.display\n4.count");
   scanf("%d",&ch);

   switch(ch)
   {
   case 1:rear=push(rear);
          if(front==NULL)
          front=rear;
          break;

   case 2:front=serve(front);
          if(front==NULL)
          rear=NULL;
          break;

   case 3:display(rear,front);
          break;

    case 4:count(rear,front);
          break;
    case 5:del_between(front);
    case 6:break;
           default: printf("invalid option");
   }
   }while(ch!=6);


   }

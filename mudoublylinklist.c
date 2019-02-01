#include<stdio.h>
#include<malloc.h>

typedef struct doubly link
{
    struct doubly link *prev;
    int info;
    struct doubly link *next;
}node;

    node *insert_beg(node *start,int x )
{
    node *p=NULL;

    p=(node*)malloc(sizeof(node));

    if(p==NULL)
    printf("\nNo memory is allocated for the node");

    p->info=x;


    p->next=NULL;
    p->prev=start;
    start->next=p;
    start=p;

return(start);


}
void insert_bet(node *start)
 {
  node *insert_node=NULL;
  node *store_address;

  insert_node=(node*)malloc(sizeof(node));
  if(insert_node==NULL)
  printf("\nno value to be returned");
  else
  {
  int value;

  printf("ENTER THE VALUE TO BE INSERTED BETWEEN NODE\n");
  scanf("%d",&value);

  insert_node->info=value;

  while(start!=value)
  {
   start=start->next;
  }
  store_address=start->next;
  start->next=insert_node;
  insert_node->prev=start;
  insert_node->next=store_address;
  store_address->prev=insert_node;

}
}
void insert_end(node *start)
{
   node *temp=NULL;

   temp=(node*)malloc(sizeof(node));

   if(temp==NULL)
    printf("\nno value to be returned");

   else

   {
       printf("\nenter he vlaue");
       scanf("%d",&temp->info);

       while(start->next!=NULL)
       {
           start=start->next;
       }
       start->next=temp;
       temp->prev=start;
       temp->next=NULL;
       }



   }
  node *del_beg(node *start)
  {
  node *temp=NULL;
  if(temp==NULL)
    printf("\nno node is present");
  else
  {
    temp=start;
    start=start->next;
    start->prev=NULL;
    free(temp);

  }
  return(start);
  }

  void del_bet(node * start)
  {
      node *store_next=NULL,store_prev=NULL;

    if(start==NULL)
    printf("\nno node is present");

    else
    {
    int value;
    printf("\nenter the value to be deleted present in the node");
    scanf("%d",&value);

    while(start!=value)
    {
        start=start->next;

    }
    store_next=start->next;
    store_prev=start->prev;

    store_prev->next=store_next;
    store_next->prev=store_prev;

    }


}

    void del_end(node *start)
    {
    if(start==NULL)
        printf("\n no node is present");
    else
    {
     node *temp;

     //temp=start;

    while(start->next!=NULL)
    {
        start=start->next;
    }
      temp=start->prev;
      temp->next=NULL;
      free(start);



    }


    }

    void main()
    {
        int x,ch;
        do{
                printf("\n1.\n2.\n3.\n4.\n5.\n6.");
                scanf("%d",&ch);
            switch(ch)
            {
            case 1:printf("\nenter the value");
                   scanf("%d",&x);
                   insert_beg(start,x);
                   break;


            case 2:


                break;



            case 3:



                break;



            case 4:


                break;




            case 5:




                break;





            case 6:


                break;




                case 7:
                break;








            }


        }while(ch!=7);
    }




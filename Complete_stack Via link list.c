    #include<stdio.h>
    #include<malloc.h>

    typedef struct stack
    {
    int info;
    struct stack *next;
    }node;

    void count_prime(node*top)
    {
        node *i;
        int j,c=0;
        int p=0;

        for(i=top;i->next!=NULL;i=i->next)
        {
            c=0;
            for(j=2;j<((i->info)/2);j++)
            {
                if(i->info%j==0)
                {
                    c=1;
                    break;

                }

            }
            if(c==0)
            {
             p=p+1;
            }
            }
            printf("no of prime nodes are %d ",p);

        }

    void del_between(node*top)
    {
        node *p,*q;

        p=top;
        q=p->next;

        if(top==NULL)
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


    void del_end(node*top)
    {
        node *p,*q;



        p=top;
        q=p->next;

        if(top==NULL)
            printf("\nno node to delete");
        else
        {
            while(q->next!=NULL)
            {
                q=q->next;
                p=p->next;
            }
            p->next=NULL;

            free(q);

        }
    }

    void insert_end(node*top)
    {
        node *p=NULL;
         p=(node*)malloc(sizeof(node));

        if(p==NULL)
            printf("\n no memory is allocated for the node");

            else{
                    printf("\nenter the number you want to add at end of link list");
                    scanf("%d",&p->info);

                while(top->next!=NULL)
                {
                    top=top->next;
                }

                top->next=p;
                p->next=NULL;



                }
    }


    void insert_between(node*top)
    {
        int num;
        node *p=NULL,*q,*store_address;

        q=top;

        p=(node*)malloc(sizeof(node));

        if(p==NULL)
            printf("\n no memory is allocated for the node");

        else
        {
            printf("\nPlease enter the data in node");
            scanf("%d",&p->info);

            printf("\nEnter the info number i.e(data) of node after which you want to add the new node");
            scanf("%d",&num);

            while(q->info!=num)
            {
                q=q->next;
            }

            store_address=q->next;


            q->next=p;
            p->next=store_address;



        }


    }


    void swap_two_nodes(node *top)
    {
        int num1,num2,temp;
        node *p,*q;


        printf("\nenter two numbers to be swapped in link list");
        scanf("%d%d",&num1,&num2);


        p=top;
        q=top;

        while(p->info!=num1)
        {
            p=p->next;
        }

        while(q->info!=num2)
        {
            q=q->next;
        }


        temp=p->info;
        p->info=q->info;
        q->info=temp;


    }


  node* reverse2(node*top)
  {
      node *p,*q,*r;
      p=NULL;
      q=top;
      r=q->next;

      while(q!=NULL)
      {
          q->next=p;
          p=q;
          q=r;
          if(r!=NULL)
            r=r->next;

      }
      return(p);
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


  void sort(node *top)
  {
      node *i,*j;
      int temp;

      if(top==NULL)
      {
          printf("\nno node is present");

      }

else{
      for(i=top;i!=NULL;i=i->next)
      {
          for(j=i->next;j!=NULL;j=j->next)
          {
            if(i->info > j->info)
            {
              temp = i->info;
              i->info = j->info;
              j->info = temp;
            }
          }
      }
          while(top!=NULL)
          {
              printf(" %d",top->info);
              top=top->next;

          }

   }
}



  node * push(node * top)
  {
    node *p=NULL;

    p=(node*)malloc(sizeof(node));
    if(p==NULL)
        printf("\nno memory is allocated for the node");
    else
        {
        printf("\nenter the number");

        scanf("%d",&p->info);
        p->next=top;
        }
        top=p;


  return(top);
  }

  node * pop(node * top)
  {
   node *temp=top;
  if(top==NULL)
  printf("\nno address is to return");

  else
      {

       printf(" %d",top->info);

       top=top->next;

      }
      free(temp);
    return(top);
  }

  void display(node * top)
  {
    if(top==NULL)
    printf("\n no node is present");


         while(top!=NULL)
         {
         printf(" %d",top->info);
         top=top->next;
         }

  }

  void count(node *top)
  {
      int c=0;
      while(top!=NULL)
      {
          c++;
          top=top->next;
      }
      printf("\ntotal no of nodes are %d",c);
      }




  void main ()
  {
  node *top=NULL;
  int ch;

  do
    {
     printf("\n1.insert\n2.delete from front\n3.display\n4.count\n5.sort\n6.reverse\n7.second method reverse\n8.swap two nodes\n9.insert between nodes\n10.insert at end\n11.Delete from end\n12.delete from  between\n13.count prime node");
     scanf("%d",&ch);

     switch(ch)
              {
              case 1:
              top=push(top);
              break;

              case 2:
              top=pop(top);
              break;

              case 3:
              display(top);
              break;

              case 4:
              count(top);
              break;

              case 5:
              sort(top);
              break;

              case 6:
              top=reverse(top);
              break;

              case 7:
              top=reverse2(top);

              case 8:
              swap_two_nodes(top);
              break;

              case 9:
              insert_between(top);
              break;

              case 10:
              insert_end(top);
              break;

              case 11:
              del_end(top);
              break;

              case 12:
              del_between(top);
              break;

              case 13:
              count_prime(top);
              break;

              case 14:
              break;
              printf("\ninvalid option");
              }

    }while(ch!=14);

  }

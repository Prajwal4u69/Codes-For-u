#include<stdio.h>
#include<stdlib.h>
struct node
{	int data;
	struct node *prev;
	struct node *next;
}a;
struct node* insert(struct node*);
void add_pos(struct node*);
void display_front(struct node*);
void display_end(struct node*);
void delete(struct node *);
int main()
{
		struct node *start;
			start=NULL;
		int n,insert_choice;
		do
		{
			printf("\nenter your choice\n1:insert()\n2:display()\n3:to delete()\n4:display_end()\n6:to quit()\n");
			scanf("%d",&n);
			switch(n)
			{
				case 1:
					printf("enter your choice 1:to insert normally \n2:to insert at any position\n");
					scanf("%d",&insert_choice);
					if(insert_choice==1)
					start=insert(start);
					else if(insert_choice==2)
					add_pos(start);
					else
					printf("enter valid choice !\n");
					break;
				case 2:
					display_front(start);
					break;
				case 4:
					display_end(start);
					break;
				case 5:
					if(start==NULL)
					printf("empty");
					else if(start->next==NULL)
					{
						free(start);
					 	start=NULL;
					}
					else
					delete(start);
					break;
			}
		}while(n!=6);
return 0;
}

struct node *insert(struct node *start)
{
	struct node *temp,*temps;
	temps=start;
	int n;
	printf("enter the value\n");
	scanf("%d",&n);
	temp=(struct node *)malloc(sizeof(a));
	if(start!=NULL)
	{
	while(start->next!=NULL)
	start=start->next;
	temp->data=n;
	temp->prev=start;
	temp->next=NULL;
	start->next=temp;
	}
	else
	{
		temp->data=n;
	//temp->prev=start;
	temp->next=NULL;
	//start->next=temp;
	}
	if(temps==NULL)
	return temp;
	else
	return temps;
}

void add_pos(struct node * start)
{
	struct node *temp,*tp;
	int pos,value;
	temp=(struct node*)malloc(sizeof(a));
	if(temp==NULL)
	printf("no memory!!!!\n");
	else
	{
		printf("enter the position\n");
		scanf("%d",&pos);
		if(pos<1)
		printf("enter valid choice\n");

		else
		{
				printf("enter the value\n");
				scanf("%d",&(temp->data));
				while(pos-2)
				{
					start=start->next;
					pos--;
					if(start==NULL&&(pos-1)!=0)
					{
						printf("invalid location\n");
					}
				}
				tp=start->next;
				start->next=temp;
				temp->next=tp;
				tp->prev=temp;
			}
	}
}

void display_front(struct node *start)
{


	if(start==NULL)
	printf("empty\n");
	else
	printf("\nelements \n");
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	//	printf("ok");
	}
}

void display_end(struct node *start)
{

}

void delete(struct node *start)
{
	struct node *temp;
	//temp=start;

			while(start->next!=NULL)
			{
				start=start->next;
			}
			temp=(start->prev)
			temp->next==NULL;
			free(start);

}

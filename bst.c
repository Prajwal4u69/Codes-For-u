#include<stdio.h>
#include<malloc.h>

typedef struct bst
{
struct bst *left;
int info;
struct bst *right;


}node;

void insert(node **rt,int num)
{

    if(*rt==NULL)
    {


    *rt=(node*)malloc(sizeof(node));
    (*rt)->left=NULL;
    (*rt)->right=NULL;
    (*rt)->info=num;
  }

    else

        if(num<(*rt)->info)
        insert(&(*rt)->left,num);
    else
        if(num>(*rt)->info)
        insert(&(*rt)->right,num);
        }



void count(node *rt,int *c)
{
if(rt!=NULL)
{
(*c)++;
count(rt->left,c);
count(rt->right,c);
}
}

void leaf(node *rt,int *c)
{
if(rt!=NULL)
{
if(rt->left==NULL && rt->right==NULL)

(*c)++;

leaf(rt->left,c);
leaf(rt->right,c);
}
}

void right(node *rt,int *c)
{
if(rt!=NULL)
{
if(rt->right!=NULL)
{
(*c)++;
right(rt->left,c);
right(rt->right,c);
}
}
}

 node* deletea(node *root, int data) {
  if (root == NULL) {
     return NULL;
  }
  if (data < root->info) {  // data is in the left sub tree.
      root->left = deletea(root->left, data);
  } else if (data > root->info) { // data is in the right sub tree.
      root->right = deletea(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        free(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        node *temp = root; // save current node as a backup
        root = root->right;
        free(temp);
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        node *temp = root; // save current node as a backup
        root = root->left;
        free(temp);
     }
     // case 4: two children
     else {
        node *temp = FindMin(root->right); // find minimal value of right sub tree
        root->info = temp->info; // duplicate the node
        root->right = deletea(root->right, temp->info); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}

 int FindMin(node *root) {
   if (root == NULL) {
      return ; // or undefined.
   }
   if (root->left != NULL) {
      return FindMin(root->left); // left tree is smaller
   }
   return root->info;
}

void display(node *rt)
{

   if(rt!=NULL)
   {
       display(rt->left);
       printf(" %d",rt->info);
       display(rt->right);
   }

}


void main()
{
node *rt=NULL;
int ch,num;
int c;

do{

printf("\n1.insert\n2count all nodes\n3countleafnode\n4cou t right children\n5delete a node\n6display in order");
scanf("%d",&ch);

switch(ch)
{
case 1:
printf("\nenter number");
scanf("%d",&num);
insert(&rt,num);
break;

case 2:
c=0;
count(rt,&c);
printf("total no of nodes are %d",c);
break;

case 3:
c=0;
leaf(rt,&c);
printf("total no of leaf nodes are %d",c);
break;

case 4:
c=0;
right(rt,&c);
printf("total no of right children are %d",c);
break;

case 5:
printf("\nenter the number you want to delete from the tree");
scanf("%d",&num);
rt=deletea(rt,num);
break;

case 6:
    display(rt);
    break;
case 7:
default:printf("\n invalid choice");
break;
}



}while(ch!=7);

}


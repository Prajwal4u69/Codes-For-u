//quick sort
#include<stdio.h>
#define err printf("ok");

void quicksort(int [],int ,int);
int main()
{

    int n,pivot,lb,rb,i;
    printf("enter the size of array\n");
    scanf("%d",&n);
    int array[n];

    printf("enter the elements of array\n");
    for(i=0;i<n;i++)
    scanf("%d",&array[i]);
    lb=0;rb=n-1;

    quicksort(array,lb,rb);
     for(i=0;i<n;i++)
    printf("%d   ",i+1);
}

void quicksort(int array[],int lb,int ub)
{  // err
        int pivot;
        pivot=array[lb];
        int i,j,s;
        i=lb;j=ub;

     //   printf("%d  %d\n",lb,ub);
        if(lb>=ub)
        return ;

        while(i<j)
        {

            while(pivot>=array[i]&&i<ub)
                  i++;

            while(pivot<=array[j]&&j>lb)
                 j--;

            if(i<j)
            {
                s=array[i];
                array[i]=array[j];
                array[j]=s;


            }
        }
        array[lb]=array[j];
        array[j]=pivot;

        quicksort(array,lb,j-1);
        quicksort(array,j+1,ub);

}

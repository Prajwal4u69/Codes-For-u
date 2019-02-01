#include<stdio.h>

void main()
{
int i,j,k,n;
float sum=0.0,x[20],c,a[30][30];

printf("\nenter the limit ");
scanf("%d",&n);

printf("\nenter the elements in the array ");
for(i=1;i<=n;i++)
{
    for(j=1;j<=(n+1);j++)
    {
        scanf("%f",&a[i][j]);
    }
}

for(j=1;j<=n;j++)
{
    for(i=1;i<=(n);i++)
    {
        if(i!=j)
        {
            c=a[i][j]/a[j][j];
            for(k=1;k<=(n+1);k++)
            {
                a[i][k]=a[i][k]-c*a[j][k];
            }


        }
    }
}

/** x[n]=a[n][n+1]/a[n][n];


for(i=n-1;i>=1;i--)
{
    sum=0;
    for(j=i+1;j<=n;j++)
    {

    sum=sum+x[j]*a[i][j];

    }
x[i]=(a[i][n+1]-sum)/a[i][i];
}**/
for(i=1;i<=n;i++)
{
    printf("\n %f ",a[i][n+1]/a[i][i]);
}

}







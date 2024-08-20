#include<stdio.h>
int main()
{
    int n,i,j,temp;
    int ar[50];
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ar[i]>ar[j])
            {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    printf("the array after sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",ar[i]);
    }
}

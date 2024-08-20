#include<stdio.h>
int main()
{
    int n,i,j,k,c=0,p;
    int a[50];
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element to be searched");
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            c=1;p=i;
        }
    }
    if(c==1)
        printf("element found in %d",p+1);
    else if (c==0)
        printf("element not found");
}

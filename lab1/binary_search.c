#include<stdio.h>
int main()
{
    int n,i,j,k,m,l,h;
    int a[50];
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the elements in ascending order");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element to be searched");
    scanf("%d",&k);
    l=0;
    h=n-1;
    m=(l+h)/2;
    while(a[m]!=k)
    {
        m=(l+h)/2;
        if (a[m]>a[k])
        {
            h=m-1;
        }
        else {l=m+1;
        }}
        if(k==a[m])
             printf("element found in %d",m+1);
        else
                printf("element not found");

}

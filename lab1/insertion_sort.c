#include<stdio.h>

int main ()
{
int n, i, j, key;
printf ("enter the number of elements");
scanf("%d",&n);
int a[n];
printf ("enter the elements");
for(i=0;i<n;i++)
{
    scanf("%d", &a[i]);
}
for(i=0;i<n;i++)
{
    key=a[i];
    for(j=i-1;j>=0 && a[j]>key; j--)
    {
        a[j+1]=a[j];
    }a[j+1]=key;
}
 printf("the array after sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}


#include<stdio.h>
#include<string.h>
void main()
{
    int l1,l2,i=0,j=0,n;
    char c1[50],c2[50];
    printf("enter string1\n");
    gets(c1);
    printf("enter sub-string \n");
    gets(c2);
    while(c1[i]!='\0')
   {
       i++;
   } l1=i;
   while(c2[j]!='\0')
   {
       j++;
   } l2=j;
   printf("enter the position");
   scanf("%d",&n);
   for(i=l1; i>=n;i--)
   {
       c1[i+l2]=c1[i];
   }
    for (i = n, j = 0; j < l2; i++, j++) {
       c1[i] = c2[j];
    }
    c1[l1+l2]='\0';
    printf("Modified string: %s\n", c1);
}

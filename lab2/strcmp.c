#include<stdio.h>
#include<string.h>
void main()
{
    int l1,l2,i=0,j=0,n=0;
    char c1[50],c2[50];
    printf("enter the string1\n");
    gets(c1);
    printf("enter the string2 \n");
    gets(c2);
    while(c1[i]!='\0')
   {
       i++;
   } l1=i;
   while(c2[j]!='\0')
   {
       j++;
   } l2=j;
   if(l1==l2){
    for(i=0;i<l1;i++)
    {
      if(c1[i]==c2[i])
      {
          n++;
      }
      else if (c1[i]!=c2[i]){
       n=0;  break;
      }

    }}
    if(l1>l2)
    printf("sting 1 > string 2");
    else if(l1<l2)
    printf("sting 1 < string 2");
    else if(n==l1)
        printf("both the strings are equal");
    else if (n==0)
        printf("the strings are not equal");
}

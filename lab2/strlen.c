#include<stdio.h>
#include<string.h>
void main()
{
    int i,n=0;
    char c[50];
    printf("enter the string\n");
    gets(c);
    for(i=0;c[i]!='\0';i++)
    {
        n++;
    }
    printf("the string length is %d\n",n);
}

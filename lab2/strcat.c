#include<stdio.h>
#include<string.h>
void main()
{
    int i=0,j=0;
    char c1[50],c2[50];
    printf("enter the string1\n");
    gets(c1);
     printf("enter the string2 \n");
    gets(c2);
    while(c1[i]!='\0')
    i++;
    while(c2[j]!='\0')
    {
        c1[i]=c2[j];
        j++;
        i++;
    }
    c1[i]='\0';
    puts(c1);
}

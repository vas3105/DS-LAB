#include<stdio.h>
#include<string.h>
void main()
{
    int l1,l2,i=0,j=0,k;
    char c1[50],c2[50];
    printf("enter the string \n");
    gets(c1);
    printf("enter the sub-string to be deleted \n");
    gets(c2);
    while(c1[i]!='\0')
   {
       i++;
   } l1=i;
   while(c2[j]!='\0')
   {
    j++;
   } l2=j;
  for (i = 0; i <= l1 - l2; ) {
        for (j = 0; j < l2; j++) {
            if (c1[i + j] != c2[j]) {
                break;
            }
        }

        if (j == l2) { 
            for (k = i; k <= l1 - l2; k++) {
                c1[k] = c1[k + l2];
            }
            l1 -= l2;
            c1[l1] = '\0';
        } else {
            i++;
        }
    }
printf("the modified string is:%s \n",c1);
}

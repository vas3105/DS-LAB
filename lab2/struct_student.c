 #include<stdio.h>
struct student
{
    int roll;
    char name[50];
    int g1,g2;
};
int read (struct student s[],int n);
int display (struct student s[],int n);
int sort (struct student s[],int n);
int main()
{
    int n;
    printf("enter the number of students");
    scanf("%d",&n);
    struct student s[n],temp;
    read (s,n);
    display(s,n);
    sort(s,n);
    return 0;
   }
   int read (struct student s[],int n){
       int i;
   for(i=0;i<n;i++)
    {
    printf("enter the name,roll number and grade of subject 1 and 2 respectively of student %d",i+1);
    scanf("%s%d%d%d",s[i].name,&s[i].roll,&s[i].g1,&s[i].g2);
    } return 0;
   }
   int display (struct student s[],int n)
   { int i;
       for(i=0;i<n;i++)
       {
           printf("Name: %s, RollNo: %d, Grade1: %d,Grade2: %d\n",s[i].name,s[i].roll,s[i].g1,s[i].g2);
       }
       return 0;
   }
   int sort (struct student s[],int n){
       struct student temp;
       int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%d\t%d\n",s[i].roll,s[i].name,s[i].g1,s[i].g2);
    }
}

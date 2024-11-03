#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left,*ryt;
};
struct node *root=NULL;
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->ryt = NULL;
    return newnode;
}
void insert(struct node **root,int data)
{
    if(*root==NULL)
    {
        *root=createnode(data);
    }
    else if(data<=(*root)->data)
    {
        insert(&((*root)->left),data);
    }
    else if(data>(*root)->data)
    {
        insert(&((*root)->ryt),data);
    }
}
void search(struct node *root,int ele)
{
    if(root==NULL)
    {
         printf("element not found\n"); return;
    }
    else if(ele==root->data)
    {
        printf("element found \n");
    }
    else if(ele<root->data)
    {
        search( root->left,ele);
    }
    else if(ele> root->data)
    {
        search( root->ryt,ele);
    }
}
void inorder(struct node *root)
{
if(root==NULL) return;
inorder(root->left);
printf("%d\t",root->data);
inorder(root->ryt);
}
int main()
{

    int n,ele;
    printf("enter the root node element");
    scanf("%d",&ele);
    struct node *root=createnode(ele);
    printf("enter the total number of elements");
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        printf("enter the element");
        scanf("%d",&ele);
        insert(&root,ele);
    }inorder(root);
printf("enter the element to search");
scanf("%d",&ele);
search(root,ele);
inorder(root);
}

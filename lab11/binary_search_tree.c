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
struct node* getSucc(struct node* temp) {
    temp= temp->ryt;
    while (temp != NULL && temp->left != NULL)
         temp =temp->left;
    return  temp;
}
struct node *removes(struct node *root,int ele)
{
    if(root==NULL)
    {
      printf("element not found"); return;
    }
        else if(ele<root->data)
        {
           root->left=removes(root->left,ele);
        }
        else if(ele>root->data)
        {
            root->ryt=removes(root->ryt,ele);
        }
        else
        {
            if (root->ryt == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        if (root->left == NULL) {
            struct node* temp = root->ryt;
            free(root);
            return temp;
        }
         struct node* succ = getSucc(root);
        root->data = succ->data;
        root->ryt = removes(root->ryt, succ->data);
    }
    return root;
}
int main()
{
     int n,ele,ch;
     printf("enter total elements in your binary search tree");
     scanf("%d",&n);
    printf("enter the root node element");
    scanf("%d",&ele);
    struct node *root=createnode(ele);
    for(int i=1;i<n;i++)
    {
        printf("enter the element");
        scanf("%d",&ele);
        insert(&root,ele);
    }
    while(1)
    {
        printf("\n1.insert\n 2.delete\n 3.search\n 4.display\n 5.exit\n");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter element to insert");
                    scanf("%d",&ele);
                    insert(&root,ele);
                    break;
            case 2: printf("enter the element to delete");
                    scanf("%d",&ele);
                    removes(root,ele);

                    break;
            case 3: printf("enter the element to search");
                    scanf("%d",&ele);
                    search(root,ele);
                    break;
           case 4:if(root->data==NULL) { printf("empty tree");}
                   else
                   {
                       printf("the binary search tree\n");
                       inorder(root);

                   }
                   break;
           case 5: printf("exiting..");
                   return 0;
           default: printf("invalid input, try again");
                    break;
        }
    }
}

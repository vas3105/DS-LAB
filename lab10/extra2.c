#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*ryt;

};
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->ryt = NULL;
    return newnode;
}
void insert(struct node** root, int data) {
    if (*root == NULL) {
        *root = createnode(data);
    } else {
        if (data < (*root)->data) {
            insert(&((*root)->left), data);
        } else {
            insert(&((*root)->ryt), data);
        }
    }
}
void inorder(struct node *root)
{
if(root==NULL) return;
inorder(root->left);
printf("%d\t",root->data);
inorder(root->ryt);
}
int traverse_left(struct node *root)
{
    if(root==NULL) return ;
    traverse_left(root->left);
    return root->data;
    traverse_left(root->ryt);
}
int traverse_ryt(struct node *root)
{
    if(root==NULL) return ;
    traverse_ryt(root->ryt);
    return root->data;
    traverse_ryt(root->left);
}
void check(struct node *root1, struct node *root2,int n1,int n2)
{
    int r1,r2,c=0;
    if(n1!=n2)
    {
        printf("trees are not equal");
    }
    else{
        if(root1==NULL || root2 ==NULL)
        {
            printf("trees are not equal");
        }
        else
        {
            for(int i=0;i<n1;i++)
            {
                r1=traverse_left(root1);
                r2=traverse_ryt(root2);
                if(r1==r2)
                    c++;
            }
            if(c==n1)
            {
                printf("trees are mirror image");
            }
            else
            {
                printf("trees are not mirror image");
            }
        }
    }
}
int main()
{
    int n1,n2,ele;
    struct node *root1=NULL;
    struct node *root2=NULL;
    printf("enter total number of elements in tree 1:\t");
    scanf("%d",&n1);
   for(int i=1;i<=n1;i++)
   {
       printf("enter element %d :",i);
       scanf("%d",&ele);
       insert(&root1,ele);
   }
   printf("enter total number of elements in tree 2:\t");
    scanf("%d",&n2);
   for(int i=1;i<=n2;i++)
   {
       printf("enter element %d :",i);
       scanf("%d",&ele);
       insert(&root2,ele);
   }
   inorder(root1);
   printf("\n");
   inorder(root2); printf("\n");
   check(root1,root2,n1,n2);
}

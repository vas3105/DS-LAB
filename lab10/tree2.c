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
int main()
{
    int n,ele;
    struct node *root=NULL;
    printf("enter total number of elements");
    scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       printf("enter element %d :",i);
       scanf("%d",&ele);
       insert(&root,ele);
   }
   inorder(root);
}

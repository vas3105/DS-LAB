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
void preorder(struct node *root)
{
    if(root==NULL) return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->ryt);
}
void postorder(struct node *root)
{
     if(root==NULL) return;
    preorder(root->left);
    preorder(root->ryt);
    printf("%d\t",root->data);
}
int depth(struct node* root, int value, int depths) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == value) {
        return depths;
    }

    int leftDepth = depth(root->left, value, depths + 1);
    if (leftDepth != -1) {
        return leftDepth;
    }

    return depth(root->ryt, value, depths + 1);
}
int ancest(struct node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }


    if (ancest(root->left, value) || ancest(root->ryt, value)) {
        printf("%d\t", root->data);
        return 1;
    }

    return 0;
}
int traverse(struct node *root, int ele) {
    if (root == NULL) return -1;

    if ((root->left && root->left->data == ele) || (root->ryt && root->ryt->data == ele)) {
        return root->data;
    }


    int leftParent = traverse(root->left, ele);
    if (leftParent != -1) return leftParent;

    return traverse(root->right, ele);
}

void parent(struct node *root, int ele) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    int parentData = traverse(root, ele);
    if (parentData != -1) {
        printf("parent of is: %d\n",parentData);
    } else {
        printf("parent not found\n", ele);
    }
}
int leafnode(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->ryt == NULL) {
        return 1;
    return leafnode(root->left)+leafnode(root->ryt);
}}
void main()
{
    int n,ch,ele,depths,count;
    struct node *root=NULL;
    printf("enter total number of elements");
    scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       printf("enter element %d :",i);
       scanf("%d",&ele);
       insert(&root,ele);
   }

    while(ch<=8)
    {
        printf("\n1.perform  In-order traversal\n");
        printf("2.Post-order traversal\n");
        printf("3.Pre-order traversal\n");
        printf("4. display the parent node\n");
        printf("5.display depth of the tree\n");
        printf("6. display ancestors of the element\n");
        printf("7.count the number of leaf nodes\n");
        printf("8.Exit\n");
        printf("enter your choice\t: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: inorder(root);
                    break;
            case 2: postorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4:printf("enter the element to find its parent");
                    scanf("%d",&ele);
                   parent(root,ele);  break;
            case 5:  printf("enter the element to find the depth of");
                     scanf("%d",&ele);
                   depths=depth(root,ele,0);
                   if(depth!=-1)
                   {
                       printf("depth of the element is %d\n",depths);
                   }
                   else
                   {
                       printf("element not found");
                   }break;
            case 6: printf("enter the element to find its ancestor");
                    scanf("%d",&ele);
                    printf("ancestors: ");
                   ancest(root,ele);
                   break;
            case 7:  count=leafnode(root);
                   printf("total leaf nodes : %d",count);
                   break;
            default: printf("invalid choice, try again");
                    break;
            case 8: printf("exiting"); ch=9;
                    break;
        }
    }
return 0;}


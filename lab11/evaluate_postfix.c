#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node
{
    char val;
    struct node *left,*ryt;
};
struct stack
{
    struct node *data;
    struct stack *next;
};
struct node *create(char d)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->val=d;
    newnode->left=newnode->ryt=NULL;
    return newnode;
};
void push(struct stack **s,struct node *head)
{
    struct stack *newstack=malloc(sizeof(struct stack));
    newstack->data=head;
    newstack->next=*s;
    *s=newstack;
}
struct node *pop(struct stack **s)
{
    if(*s==NULL)
    {
        return NULL;
    }
    struct stack *temp=*s;
    *s=(*s)->next;
    struct node *n=temp->data;
    free(temp);
    return n;
};
struct node *buildtree(char postfix[])
{
    struct stack *s=NULL;
    for(int i=0;postfix[i]!='\0';i++)
    {
        char ch=postfix[i];
        if(isdigit(ch))
        {
            push(&s,create(ch));
        }
        else if(ch=='+'|| ch=='-'|| ch=='/'|| ch=='*')
        {
            struct node *op=create(ch);
            op->left=pop(&s);
            op->ryt=pop(&s);
            push(&s,op);
        }
    }
    return pop(&s);
};
int eval(struct node *root)
{
    if(root->left==NULL && root->ryt==NULL)
    {
        return root->val-'0';
    }
    int leftval=eval(root->left);
    int rytval=eval(root->ryt);
    switch(root->val)
    {
        case '+': return leftval+rytval;
        case '-': return leftval-rytval;
        case '/': return leftval/rytval;
        case '*': return leftval*rytval;
    }return 0;
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    inorder(root->left);
    printf("%c",root->val);
    inorder(root->ryt);
}
int main()
{
    char postfix[500];
    printf("enter the postfix expression");
    fgets(postfix,500,stdin);
    postfix[strcspn(postfix,"\n")]=0;
    struct node *build=buildtree(postfix);
    printf("\ninorder traversal\t");
    inorder(build);
    int r=eval(build);
    printf("result: %d",r);
}

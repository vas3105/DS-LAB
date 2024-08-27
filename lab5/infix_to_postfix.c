#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 100
struct stack
{
    int top;
    char s[MAX];
};
void init(struct stack *s)
{
    s->top=-1;
}
int push(struct stack *s,char  ele)
{
    if(s->top==MAX-1)
    {
        printf("overflow");
    }
    else
    {
        s->top++;
        s->s[s->top]=ele;

    }
}
char pop(struct stack *s)
{
    if(s->top==-1)
    {
        printf("underflow");
    }
    else
    {
        char ele=s->s[s->top];
        s->top--;
        return ele;

    }
}
int peek(struct stack *s)
{
    if(s->top==-1)
    {
        return'\0';
    }
    else{
        return s->s[s->top];
    }
}
int check(int ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int operators(int op)
{
    switch(op)
    {
        case '+':return 1;
        case '-':return 1;
        case '*': return 2;
        case '/': return 2;
        case '^':return 3;
        default: return 0;

    }

}
int convert(char infix[],char postfix[])
{
    struct stack s;
    init(&s);
    int j=0;
    for(int i=0;i<strlen(infix);i++)
    {
        char e=infix[i];
        if(isalnum(e))
        {
            postfix[j++]=e;
        }
        if(e=='(')
        {
            push(&s,e);
        }
        else if(e==')')
        {
            while(s.top!=-1 && peek(&s)!='(')
            {
                 postfix[j++] = pop(&s);
            }pop(&s);
        }
        else if(check(e))
        {
            while (s.top!=-1 && operators(peek(&s)) >= operators(e)) {
                postfix[j++] = pop(&s);
            }
            push(&s, e);
        }
    }while (s.top!=-1) {
        postfix[j++] = pop(&s);
    }
    postfix[j]='\0';

}
int main()
{
    char infix[50],postfix[50];
     printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;

    convert(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

}

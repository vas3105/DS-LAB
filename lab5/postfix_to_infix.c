#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
struct stack
{
    int top;
    char s[MAX][MAX];
};
void init(struct stack *stk)
{
    stk->top = -1;
}
void push(struct stack *stk, char *exp)
{
    if (stk->top == MAX - 1)
    {
        printf("Stack overflow\n");
    } else {
        stk->top++;
        strcpy(stk->s[stk->top], exp);
    }
}
void pop(struct stack *stk, char *exp)
{
    if (stk->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        strcpy(exp, stk->s[stk->top]);
        stk->top--;
    }
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
void convert(char postfix[], char infix[]) {
    struct stack s;
    init(&s);

    char top1[MAX], top2[MAX], temp[MAX];

    for (int i = 0; i < strlen(postfix); i++) {
        char ele = postfix[i];

        if (isalpha(ele)) {
            char operand[2] = {ele, '\0'};
            push(&s, operand);
        } else if (isOperator(ele)) {
            pop(&s, top1);
            pop(&s, top2);
            sprintf(temp, "(%s%c%s)", top2, ele, top1);
            push(&s, temp);
        }
    }
    pop(&s, infix);
}
int main() {
    char postfix[MAX], infix[MAX];
    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = 0;
    convert(postfix, infix);
    printf("Infix expression: %s\n", infix);
    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct stack {
    int top;
    char stk[MAX];
};

void init(struct stack *s);
void push(struct stack *s, char ele);
char pop(struct stack *s);
char peek(struct stack *s);
int precedence(char op);
int isOperator(char c);
void reverse(char* str);
void convert(char *infix, char *prefix);

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';
    convert(infix, prefix);
    printf("The prefix expression is: %s\n", prefix);
    return 0;
}
void init(struct stack *s) {
    s->top = -1;
}
void push(struct stack *s, char ele) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        s->stk[++(s->top)] = ele;
    }
}
char pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return s->stk[(s->top)--];
    }
}
char peek(struct stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->stk[s->top];
}
int precedence(char op) {
    switch (op) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
int isOperator(char c) {
    return (c == '/' || c == '+' || c == '*' || c == '-' || c == '^');
}
void reverse(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
void convert(char *infix, char *prefix) {
    struct stack s;
    init(&s);
    int k = 0;
    int length = strlen(infix);
    char reversedInfix[MAX];
    reverse(infix);
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (infix[i] == ')') {
            reversedInfix[i] = '(';
        } else {
            reversedInfix[i] = infix[i];
        }
    }
    reversedInfix[length] = '\0';


    for (int i = 0; reversedInfix[i]; i++) {
        char c = reversedInfix[i];

        if (isalnum(c)) {
            prefix[k++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                prefix[k++] = pop(&s);
            }
            pop(&s);
        } else {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(c)) {
                prefix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (s.top != -1) {
        prefix[k++] = pop(&s);
    }
    prefix[k] = '\0';
    reverse(prefix);
}

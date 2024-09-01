#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct stack {
    int top;
    char s[MAX][MAX]; 
};

void init(struct stack *s) {
    s->top = -1;
}

void push(struct stack *s, char *ele) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        strcpy(s->s[++(s->top)], ele);
    }
}

char* pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return NULL;
    } else {
        return s->s[(s->top)--];
    }
}

char* peek(struct stack *s) {
    if (s->top == -1) {
        return NULL;
    }
    return s->s[s->top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void convert(struct stack *s, char prefix[], char infix[]) {
    int length = strlen(prefix);
    char op1[MAX], op2[MAX], temp[MAX];

    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isspace(ch)) {
            continue;
        }

        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            push(s, operand);
        } else if (isOperator(ch)) {
            // Pop two operands from the stack
            strcpy(op1, pop(s));
            strcpy(op2, pop(s));
            snprintf(temp, sizeof(temp), "(%s %c %s)", op1, ch, op2);
            push(s, temp);
        }
    }
    strcpy(infix, pop(s));
}

int main() {
    char prefix[MAX], infix[MAX];
    struct stack s;
    
    init(&s);

    printf("Enter the prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strcspn(prefix, "\n")] = '\0';  // Remove newline character

    convert(&s, prefix, infix);
    printf("The infix expression is: %s\n", infix);

    return 0;
}

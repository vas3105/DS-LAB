#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char stack[MAX][MAX];
int top = -1;

void push(char* str) {
    if (top < MAX - 1) {
        strcpy(stack[++top], str);
    } else {
        printf("overflow");
    }
}

char* pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("underflow");
        return NULL;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void prefixToPostfix(char* prefix, char* postfix) {
    int length = strlen(prefix);
    char op1[MAX], op2[MAX], temp[MAX];

    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isspace(ch)) {
            continue;
        }

        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            push(operand);
        } else if (isOperator(ch)) {
            strcpy(op1, pop());
            strcpy(op2, pop());
            snprintf(temp, sizeof(temp), "%s%s%c", op1, op2, ch);
            push(temp);
        }
    }

    strcpy(postfix, pop());
}

int evaluatePostfix(char* postfix) {
    int stack[MAX];
    int top = -1;

    void push(int num) {
        stack[++top] = num;
    }

    int pop() {
        return stack[top--];
    }

    int solvePostfix(char* postfix) {
        int i, num1, num2, result;

        for (i = 0; i < strlen(postfix); i++) {
            if (isdigit(postfix[i])) {
                push(postfix[i] - '0');
            } else if (isOperator(postfix[i])) {
                num2 = pop();
                num1 = pop();
                switch (postfix[i]) {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;
                    case '/': result = num1 / num2; break;
                    case '^': result = num1 ^ num2; break;
                    default: printf("Invalid operator\n"); return -1;
                }
                push(result);
            }
        }
        return pop();
    }

    return solvePostfix(postfix);
}

int main() {
    char prefix[MAX], postfix[MAX];
    printf("Enter the prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strcspn(prefix, "\n")] = '\0';

    prefixToPostfix(prefix, postfix);
    int result = evaluatePostfix(postfix);

    printf("The result is: %d\n", result);
    return 0;
}

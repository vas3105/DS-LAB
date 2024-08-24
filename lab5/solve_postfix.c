#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push(int num) {
    stack[++top] = num;
}

int pop() {
    return stack[top--];
}

int solve(char postfix[]) {
    int i, num1, num2, result;
    for (i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            num2 = pop();
            num1 = pop();
            switch (postfix[i]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                default:
                    printf("invalid operator\n");
                    return -1;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("enter a postfix expression: ");
    fgets(postfix, MAX, stdin);
    postfix[strlen(postfix) - 1] = '\0';
    int result = solve(postfix);
    if (result != -1) {
        printf("result: %d\n", result);
    }
    return 0;
}

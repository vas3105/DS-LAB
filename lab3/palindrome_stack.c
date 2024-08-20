#include <stdio.h>
#include <string.h>
#define MAXSIZE 60
#include<stdbool.h>
struct stack {
    char s[MAXSIZE];
    int top;
};

//  initialize the stack
void initialize(struct stack *s) {
    s->top = -1;
}

// check if the stack is empty
bool isEmpty(struct stack *s) {
    return s->top == -1;
}

//  check if the stack is full
bool isFull(struct stack *s) {
    return s->top == MAXSIZE - 1;
}

//  push an item
void push(struct stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow, cannot push %c\n", item);
        return;
    }
    s->top++;
    s->s[s->top] = item;
}

//  pop
char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow, cannot pop\n");
        return '\0';
    }
    char poppedItem = s->s[s->top];
    s->top--;
    return poppedItem;
}


void check_Palindrome(struct stack *s, char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        push(s, str[i]);
    }

    bool isPalin = true;
    for (int i = 0; i < length; i++) {
        if (str[i] != pop(s)) {
            isPalin = false;
            break;
        }
    }

    if (isPalin) {
        printf("It's a palindrome\n");
    } else {
        printf("It's not a palindrome\n");
    }
}
int removeline(char *str)
{
    int i = 0;


    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
        i++;
    }
}
// Main function
int main() {
    struct stack s;
    char str[50];
    initialize(&s);
    printf("Enter the no or word: ");
    fgets(str, sizeof(str), stdin);
    removeline(str);
    check_Palindrome(&s, str);

    return 0;
}

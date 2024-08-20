#include <stdio.h>
#include <string.h>
#define MAXSIZE 60
#include<stdbool.h>
#include<math.h>
struct stack {
    char s[MAXSIZE];
    int top;
};
void initialize(struct stack *s) {
    s->top = -1;
}

bool isEmpty(struct stack *s) {
    return s->top == -1;
}

bool isFull(struct stack *s) {
    return s->top == MAXSIZE - 1;
}

//  push an item
void push(struct stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow");
        return;
    }
    s->top++;
    s->s[s->top] = item;
}
//  pop
char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow \n");
        return '\0';
    }
    char poppedItem = s->s[s->top];
    s->top--;
    return poppedItem;
}

void convert(struct stack *s, int n){
 while (n > 0) {
        int remainder = n % 2;
        push(s, remainder + '0');
        n /= 2;
    }
    printf("Binary: ");
    while (!isEmpty(s)) {
        printf("%c", pop(s));
    }
    printf("\n");
}

void hexa(struct stack *s, int n)
{
    char hexDigits[] = "0123456789ABCDEF";

    while (n > 0) {
        int remainder = n % 16;
        push(s, hexDigits[remainder]);
        n /= 16;
    }
    printf("Hexadecimal: ");
    while (!isEmpty(s)) {
        printf("%c", pop(s));
    }
    printf("\n");
}
int main()
{
    int n,ch,t=1;
    struct stack s;
    initialize(&s);

   while(t==1){
    printf("convert decimal to 1.binary 2.hexadecimal 3.Exit");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
            printf("enter a decimal number");
            scanf("%d",&n);
            convert(&s,n);
             break;
    case 2:  printf("enter a decimal number");
             scanf("%d",&n);
             hexa(&s,n);
             break;
    case 3: t=0;
        break;
    default: printf("error\n");
    }}
    return 0;

}

#define MAX 100
#include<string.h>
#include<stdbool.h>
typedef struct {
    int top;
    char s[MAX];
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *queue=(MyQueue *)malloc(sizeof(MyQueue));
    queue->top=-1;
     return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj->top==MAX-1)
    { return ;}
    else
    {
        obj->top++;
        obj->s[obj->top]=x;
    }

}

int myQueuePop(MyQueue* obj) {

    if(obj->top==-1)
    { return '\0';}
    else
    {  char temp = obj->s[0];
     for (int i = 1; i <= obj->top; i++) {
            obj->s[i - 1] = obj->s[i]; 
        }
       obj->top--;
        return temp;
    }
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top==-1)
    { return 0;}
    else
    {
        return obj->s[0];}
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top==-1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {

    MyQueue* queue = myQueueCreate();
    printf("Pushing 1, 2, 3 to the queue.\n");
    myQueuePush(queue, '1');
    myQueuePush(queue, '2');
    myQueuePush(queue, '3');
    printf("Front element: %c\n", myQueuePeek(queue));
    printf("Popped element: %c\n", myQueuePop(queue));
    printf("Popped element: %c\n", myQueuePop(queue));
    printf("Front element after two pops: %c\n", myQueuePeek(queue));
    printf("Is queue empty? %s\n", myQueueEmpty(queue) ? "Yes" : "No");
    printf("Popped element: %c\n", myQueuePop(queue));
    printf("Is queue empty after last pop? %s\n", myQueueEmpty(queue) ? "Yes" : "No");
    myQueueFree(queue);

    return 0;
}

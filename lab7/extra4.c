#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack\n", data);
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty, nothing to pop!\n");
        return -1;
    }
    int poppedData = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped %d from the stack\n", poppedData);
    return poppedData;
}
int isStackEmpty(struct Stack* stack) {
    return stack->top == NULL;
}
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into the queue\n", data);
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty, nothing to dequeue!\n");
        return -1;
    }
    int dequeuedData = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("Dequeued %d from the queue\n", dequeuedData);
    return dequeuedData;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void displayStack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    struct Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    displayStack(stack);
    pop(stack);
    displayStack(stack);


    struct Queue* queue = createQueue();
    enqueue(queue, 100);
    enqueue(queue, 200);
    enqueue(queue, 300);
    displayQueue(queue);
    dequeue(queue);
    displayQueue(queue);

    return 0;
}

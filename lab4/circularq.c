#include<stdio.h>
#define max 3
struct Queue {
int front, rear;
int q[max];
};
void enq (struct Queue *queue,int n);
void deq(struct Queue *queue);
void display(struct Queue *queue);
int main()
{
    struct Queue queue;
     queue.front = -1;
    queue.rear = -1;
    int choice, ele;
    while (1) {
        printf("\n1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
switch (choice) {
    case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &ele);
            enq(&queue,ele);
            break;
    case 2:
             deq(&queue);
           /* if (ele != -1)
            printf("Deleted item: %d\n", ele);
            else
            printf("Queue is empty.\n");*/
            break;
    case 3:
            display(&queue);
            break;
    case 4:
            printf("Exiting the program.\n");
            return 0;
    default:
            printf("invalid input");
            break;
                }
    }
}
void enq(struct Queue *queue,int n)
{
    if(queue->front==-1 && queue->rear==-1)
    {
        queue->front=0;
        queue->rear=0;
        queue->q[queue->rear] = n;
    }
        else if((queue->rear+1)%max==queue->front)
        {

            printf("overflow");
        }
        else
        {
            queue->rear=(queue->rear+1)%max;
            queue->q[queue->rear] = n;
        }

}
void deq(struct Queue *queue)
{
    if(queue->front==-1 && queue->rear==-1)

    {
        printf("underflow");
    }
    else if(queue->front==queue->rear)
    {
        printf("dequeued element %d", queue->q[queue->front]);
        queue->front=-1;
        queue->rear=-1;
    }
    else
    {
        int x=queue->q[queue->front];
        printf("dequeued element = %d",x);
        queue->front=(queue->front+1)%max;
    }
}
void display(struct Queue *queue)
{
    int i=queue->front-1;
    if(queue->front==-1 && queue->rear==-1)
    {
        printf("queue is empty");
    }
    do
    {
        i=(i+1)%max;
        int y=queue->q[(queue->front + i) % max];
        printf("%d",y);
    }while(i==max-1);
}


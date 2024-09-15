#include<stdio.h>
struct node
{
 int data;
 struct node *prev;
 struct node *next;
};
//part i
int insert_from_rear(struct node *head,int ele)
{
     struct node* newNode = malloc(sizeof(struct node));
     struct node* current = head;
     newNode->data=ele;
     while (current->next != NULL) {
     current = current->next;
     }
    current->next = newNode;
    newNode->prev = current;
    newNode->next=NULL;
    return 0;

}
//part ii
void remove_rear(struct node *head)
{
    struct node *current =head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
     if (current->prev != NULL) {
        current->prev->next = NULL;
    } else
    {
    head = NULL;
    }

    free(current);
}
//part iii
void insert_any(struct node **head,int pos,int ele)
{
    struct node *temp = *head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = NULL;
    new_node->prev=NULL;
    if (pos == 1) {
        new_node->next = *head;
        if (*head != NULL) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
     if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev=temp;
}
//part iv
int remove_pos(struct node **head,int pos)
{
    if (*head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct node *temp = *head;
    if (pos == 1) {
        *head = temp->next;
        if(*head!=NULL)
        {
            (*head)->prev=NULL;
        }
        free(temp);
        return;
    }
    struct node *previ = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        previ = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    previ->next = temp->next;
   if(temp->next!=NULL){
    temp->next->prev=previ;
   }
    free(temp);

}
//part v
void insert_after(struct node **head,int ele,int pos)
{
     struct node *temp = *head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = NULL;
    new_node->prev=NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
     if(temp->next!=NULL)
    {
        temp->next->prev=new_node;
    }
    temp->next = new_node;
    new_node->prev=temp;
}
//part vi
void insert_before(struct node **head,int ele, int pos)
{
     struct node *temp = *head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = NULL;
    new_node->prev=NULL;
    if (pos == 1) {
        new_node->next = *head;
        if(*head!=NULL)
        {
            (*head)->prev=new_node;
        }
        *head = new_node;
        return;
    }
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    if(temp->next!=NULL)
    {
        temp->next->prev=new_node;
    }
    temp->next = new_node;
    new_node->prev=temp;
}
//part vii
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("node is empty");
        return;
    }
     struct node* current = head;
    printf("Doubly linked list elements: ");
    while (current != NULL)
    {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
}
//part viii
void reverseLL(struct node **head) {
    struct node *previous = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        current->prev =next;
        previous = current;
        current = next;
    }
    *head = previous;
}
int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    int n, ch, ele, pos;

    printf("Enter total nodes: ");
    scanf("%d", &n);
    // Allocate and initialize the first node
    head = malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the 1st element: ");
    scanf("%d", &head->data);
    head->next = NULL;
    head->prev = NULL;
    tail = head;

    // Add the rest nodes
    for (int i = 2; i <= n; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter element %d: ", i);
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

    //menu to perform
    while (1) {
        printf("\n1. Insert an element from rear end of list\n");
        printf("2. Delete an element from rear end\n");
        printf("3. Insert an element at a given position\n");
        printf("4. Delete an element from given position\n");
        printf("5. Insert an element after another\n");
        printf("6. Insert an element before another element\n");
        printf("7. Traverse(display) the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                insert_from_rear(head, ele);
                break;
            case 2:
                remove_rear(&head);
                break;
            case 3:
                printf("Enter the position to insert element: ");
                scanf("%d", &pos);
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                insert_any(&head, pos, ele);
                break;
            case 4:
                printf("Enter the position to remove: ");
                scanf("%d", &pos);
                remove_pos(&head, pos);
                break;
            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                printf("Enter the position after which to insert: ");
                scanf("%d", &pos);
                insert_after(&head, ele, pos);
                break;
            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                printf("Enter the position before which to insert: ");
                scanf("%d", &pos);
                insert_before(&head, ele, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                reverseLL(&head);
                display(head);
                break;
            case 9:
                printf("Exiting the program\n");
                // Free all nodes
                while (head != NULL) {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void insert_from_rear(struct node **head, int ele) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = ele;
    newNode->next = NULL;

    if (*head == NULL) { // If the list is empty, new node becomes the head
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void concat(struct node **head1, struct node *head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct node *current = *head1;

    // Traverse to the last node of head1
    while (current->next != NULL) {
        current = current->next;
    }

    // Link the last node of head1 to head2
    current->next = head2;
    if (head2 != NULL) {
        head2->prev = current;
    }
}

void display(struct node *head) {
    printf("Concated linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, ele;
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("Enter total elements of 1st list: ");
    scanf("%d", &n1);

    // Create the first list
    for (int i = 1; i <= n1; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &ele);
        insert_from_rear(&head1, ele);
    }

    printf("Enter total elements of 2nd list: ");
    scanf("%d", &n2);

    // Create the second list
    for (int i = 1; i <= n2; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &ele);
        insert_from_rear(&head2, ele);
    }

    // Concatenate the lists
    concat(&head1, head2);


    display(head1);

    return 0;
}

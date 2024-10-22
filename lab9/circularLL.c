#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = newnode->next = NULL;
    return newnode;
}


void insert_end(struct Node** head, int data) {
    struct Node* newnode = createNode(data);


    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode->prev = newnode;
        return;
    }

    struct Node* last = (*head)->prev;

    newnode->next = *head;
    (*head)->prev = newnode;
    newnode->prev = last;
    last->next = newnode;
}
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prevNode = NULL;

    do {
        if (current->data == data) {
            if (current->next == current && current->prev == current) {

                *head = NULL;
            } else {

                if (current == *head) {
                    *head = current->next;
                }

                struct Node* prevNode = current->prev;
                struct Node* nextNode = current->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
            }

            free(current);
            printf("Node with data %d deleted.\n", data);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Element %d not found in the list.\n", data);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;

            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exit.\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

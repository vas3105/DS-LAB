#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createLinkedList() {
    int data;
    printf("Enter data (press -1 to end): ");
    scanf("%d", &data);


    if (data == -1) {
        return NULL;
    }


    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;


    newNode->next = createLinkedList();

    return newNode;
}

void traverseLinkedList(struct Node* head) {

    if (head == NULL) {
        return;
    }

    printf("%d -> ", head->data);

    traverseLinkedList(head->next);
}

int main() {

    struct Node* head = createLinkedList();

    printf("Linked List: ");
    traverseLinkedList(head);
    printf("NULL\n");

    return 0;
}

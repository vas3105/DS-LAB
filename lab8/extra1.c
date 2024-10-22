#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

int search(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

struct Node* unionLists(struct Node* list1, struct Node* list2) {
    struct Node* unionList = NULL;


    struct Node* temp = list1;
    while (temp != NULL) {
        if (!search(unionList, temp->data)) {
            insertEnd(&unionList, temp->data);
        }
        temp = temp->next;
    }

    temp = list2;
    while (temp != NULL) {
        if (!search(unionList, temp->data)) {
            insertEnd(&unionList, temp->data);
        }
        temp = temp->next;
    }

    return unionList;
}
struct Node* intersectionLists(struct Node* list1, struct Node* list2) {
    struct Node* intersectionList = NULL;
    struct Node* temp = list1;
    while (temp != NULL) {
        if (search(list2, temp->data) && !search(intersectionList, temp->data)) {
            insertEnd(&intersectionList, temp->data);
        }
        temp = temp->next;
    }

    return intersectionList;
}
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    insertEnd(&list1, 10);
    insertEnd(&list1, 20);
    insertEnd(&list1, 30);
    insertEnd(&list2, 20);
    insertEnd(&list2, 30);
    insertEnd(&list2, 40);
    insertEnd(&list2, 50);

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    struct Node* unionList = unionLists(list1, list2);
    printf("Union of List 1 and List 2: ");
    displayList(unionList);
    struct Node* intersectionList = intersectionLists(list1, list2);
    printf("Intersection of List 1 and List 2: ");
    displayList(intersectionList);

    return 0;
}

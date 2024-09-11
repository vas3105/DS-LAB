#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
//part i
void insert_before(int ele, int pos, struct node **head) {
    struct node *temp = *head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = NULL;

    if (pos == 1) {
        new_node->next = *head;
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
    temp->next = new_node;
}
//part ii
void insert_after(int ele, int pos, struct node **head) {
    struct node *temp = *head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = NULL;

    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}
//part iii
void remove_node(struct node **head, int pos) {
    if (*head == NULL) {
        printf("list is empty\n");
        return;
    }

    struct node *temp = *head;

    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct node *prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}
//part iv
void display(struct node *head) {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//part v
void reverseLL(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
//part vi
void sort(struct node *head) {
    if (head == NULL) {
        return;
    }

    struct node *current = head;
    struct node *index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
//part vii
void delete_alnodes(struct node **head) {
    if (*head == NULL) {
        printf("list is empty\n");
        return;
    }

    struct node *temp = *head;
    struct node *prev = NULL;
    int pos = 1;

    while (temp != NULL) {
        if (pos % 2 == 0) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
        pos++;
    }
}
//part viii
void insert_sort(struct node **head, int ele) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= ele) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL && current->next->data < ele) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Main function
int main() {
    struct node *head = NULL;
    int ch, ele, pos, rem, n;

    printf("Enter total nodes: ");
    scanf("%d", &n);
    printf("Enter the 1st element: ");
    head = malloc(sizeof(struct node));
    scanf("%d", &head->data);
    head->next = NULL;

    struct node *tail = head;
    for (int i = 2; i <= n; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        printf("Enter element %d: ", i);
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }

    while (1) {
        printf("\n1. Insert an element before another element in the existing list\n");
        printf("2. Insert an element after another element in the existing list\n");
        printf("3. Delete an element\n");
        printf("4. Traverse (display) the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node in the list\n");
        printf("8. Insert an element in a sorted list such that the order is maintained\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                printf("Enter the position before which to insert: ");
                scanf("%d", &pos);
                insert_before(ele, pos, &head);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                printf("Enter the position after which to insert: ");
                scanf("%d", &pos);
                insert_after(ele, pos, &head);
                break;

            case 3:
                printf("Enter the position of the element to be removed: ");
                scanf("%d", &rem);
                remove_node(&head, rem);
                break;

            case 4:
                display(head);
                break;

            case 5:
                reverseLL(&head);
                display(head);
                break;

            case 6:
                sort(head);
                break;

            case 7:
                delete_alnodes(&head);
                break;

            case 8:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                insert_sort(&head, ele);
                break;

            case 9:
                printf("Exiting the program\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

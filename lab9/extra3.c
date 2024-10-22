#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

struct Node* createHeaderNode() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next = head;
    head->prev = head;
    return head;
}

void insert(struct Node* head, int coeff, int exp) {
    struct Node* newnode = createNode(coeff, exp);
    struct Node* current = head->next;


    while (current != head && current->exp > exp) {
        current = current->next;
    }

    if (current != head && current->exp == exp) {

        current->coeff += coeff;
        if (current->coeff == 0) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
        }
        free(newnode);
    } else {
        newnode->next = current;
        newnode->prev = current->prev;
        current->prev->next = newnode;
        current->prev = newnode;
    }
}

struct Node* solve(struct Node* poly1, struct Node* poly2) {
    struct Node* result = createHeaderNode();
    struct Node* temp1 = poly1->next;
    struct Node* temp2 = poly2->next;

    while (temp1 != poly1 && temp2 != poly2) {
        if (temp1->exp == temp2->exp) {
            insert(result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            insert(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            insert(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != poly1) {
        insert(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != poly2) {
        insert(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

void display(struct Node* poly) {
    struct Node* current = poly->next;
    if (current == poly) {
        printf("0\n");
        return;
    }

    while (current != poly) {
        if (current->coeff > 0 && current != poly->next)
            printf(" + ");
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = createHeaderNode();
    struct Node* poly2 = createHeaderNode();

    int n1, n2, coeff, exp;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d : ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insert(poly1, coeff, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d : ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insert(poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    struct Node* result = solve(poly1, poly2);


    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}

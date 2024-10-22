#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insert(struct Node* header, int coeff, int exp) {
    struct Node* newnode = createNode(coeff, exp);
    struct Node* current = header->next;

    while (current != header && current->exp > exp) {
        current = current->next;
    }

    if (current != header && current->exp == exp) {
        current->coeff += coeff;
        free(newnode);
    } else {
        newnode->next = current;
        newnode->prev = current->prev;
        current->prev->next = newnode;
        current->prev = newnode;
    }
}
struct Node* solve(struct Node* poly1, struct Node* poly2) {
    struct Node* result = createNode(0, 0);
    result->next = result;
    result->prev = result;

    struct Node* p1 = poly1->next;
    struct Node* p2;

    while (p1 != poly1) {
        p2 = poly2->next;
        while (p2 != poly2) {
            int newCoeff = p1->coeff * p2->coeff;
            int newExp = p1->exp + p2->exp;
            insert(result, newCoeff, newExp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    return result;
}

void display(struct Node* header) {
    struct Node* current = header->next;

    if (current == header) {
        printf("0\n");
        return;
    }

    while (current != header) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != header) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}


int main() {
    struct Node* poly1 = createNode(0, 0);
    struct Node* poly2 = createNode(0, 0);

    poly1->next = poly1;
    poly1->prev = poly1;
    poly2->next = poly2;
    poly2->prev = poly2;

    int n1, n2, coeff, exp;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insert(poly1, coeff, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
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

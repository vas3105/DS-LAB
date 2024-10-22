#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
      int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int coeff, int exp) {
    struct Node* newnode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newnode->next = *head;
        *head = newnode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        if (current->exp == exp) {
            current->coeff += coeff;
            free(newnode);
        } else {
            newnode->next = current->next;
            current->next = newnode;
        }
    }
}

struct Node* solve(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {

            insert(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {

            insert(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {

            insert(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insert(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}
void display(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int n1, n2, coeff, exp;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insert(&poly1, coeff, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insert(&poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    struct Node* result = solve(poly1, poly2);


    printf("answer :");
    display(result);

    return 0;
}

#include<stdio.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
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
int concat(struct node **head1,struct node *head2)
{
  if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct node *current = *head1;
   /* while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    if (head2 != NULL) {
        head2->prev = current;
    }*/
    while(head2->next!=NULL && *head1->next==NULL)
    {
        insert_from_rear(head1,head2->data);
        head1->next=NULL;
        head2=head2->next;
    }
}

void display(struct node *head) {
    printf("Doubly linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    int n1,n2,ele;
    struct node *head1 = NULL;
    struct node *tail1 = NULL;
    struct node *head2 = NULL;
    struct node *tail2 = NULL;

    printf("Enter total elements of 1st node: ");
    scanf("%d", &n1);
  //1st node head
    head1 = malloc(sizeof(struct node));
    printf("Enter the 1st element: ");
    scanf("%d", &head1->data);
    head1->next = NULL;
    head1->prev = NULL;
    tail1 = head1;

    // Add the rest nodes of 1
    for (int i = 2; i <= n1; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        printf("Enter element %d: ", i);
        scanf("%d", &new_node->data);
        insert_from_rear(head1,new_node->data);
    }

    printf("Enter total elements of 2nd node: ");
    scanf("%d", &n2);
   //2nd node head
    head2 = malloc(sizeof(struct node));
    printf("Enter the 1st element: ");
    scanf("%d", &head2->data);
    head2->next = NULL;
    head2->prev = NULL;
    tail2 = head2;

    // Add the rest nodes of 2
    for (int i = 2; i <= n2; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        printf("Enter element %d: ", i);
        scanf("%d", &new_node->data);
       insert_from_rear(head2,new_node->data);
    }
    concat(&head1,head2);
    display(head1);


}

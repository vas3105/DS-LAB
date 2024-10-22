#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Booking {
    char userName[50];   
    int duration;        
    struct Booking* next; 
    struct Booking* prev;  
};

struct Booking* createBooking(char* name, int duration) {
    struct Booking* newBooking = (struct Booking*)malloc(sizeof(struct Booking));
    strcpy(newBooking->userName, name);
    newBooking->duration = duration;
    newBooking->next = newBooking->prev = NULL;
    return newBooking;
}

struct Booking* createHeaderNode() {
    struct Booking* head = (struct Booking*)malloc(sizeof(struct Booking));
    head->next = head;
    head->prev = head;
    return head;
}

void insertBooking(struct Booking* head, char* name, int duration) {
    struct Booking* newBooking = createBooking(name, duration);
    
    struct Booking* last = head->prev;
    newBooking->next = head;
    newBooking->prev = last;
    last->next = newBooking;
    head->prev = newBooking;
}

void display(struct Booking* head) {
    if (head->next == head) {
        printf("No bookings in the queue.\n");
        return;
    }

    struct Booking* temp = head->next;
    printf("Current washing machine booking queue:\n");
    while (temp != head) {
        printf("User: %s, Duration: %d minutes\n", temp->userName, temp->duration);
        temp = temp->next;
    }
}

void processBookings(struct Booking* head) {
    if (head->next == head) {
        printf("No bookings to process.\n");
        return;
    }

    struct Booking* current = head->next;

    printf("Processing booking for %s, Duration: %d minutes\n", current->userName, current->duration);

    struct Booking* temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(temp);
}

int main() {
    struct Booking* head = createHeaderNode();
    int choice, duration;
    char name[50];

    do {
        printf("\nWashing Machine Rental System:\n");
        printf("1. Add a booking\n");
        printf("2. Process next booking\n");
        printf("3. Display current queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                
                printf("Enter the user's name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0'; 
                printf("Enter the duration (in minutes): ");
                scanf("%d", &duration);
                insertBooking(head, name, duration);
                break;
            
            case 2:
               
                processBookings(head);
                break;

            case 3:
                
                display(head);
                break;

            case 4:
                printf("Exiting the system.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

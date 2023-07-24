#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone_number[20];
    struct Contact* next;
} Contact;

Contact* createContact(char name[], char phone_number[]) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone_number, phone_number);
    newContact->next = NULL;
    return newContact;
}

void addContact(Contact** head, char name[], char phone_number[]) {
    Contact* newContact = createContact(name, phone_number);
    if (*head == NULL) {
        *head = newContact;
    } else {
        Contact* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
}

void deleteContact(Contact** head, char name[]) {
    if (*head == NULL) {
        return;
    }
    if (strcmp((*head)->name, name) == 0) {
        Contact* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Contact* current = *head;
    while (current->next != NULL) {
        if (strcmp(current->next->name, name) == 0) {
            Contact* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

char* searchContact(Contact* head, char name[]) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->phone_number;
        }
        current = current->next;
    }
    return NULL;
}

void displayContacts(Contact* head) {
    if (head == NULL) {
        printf("Phone Directory is empty.\n");
        return;
    }
    Contact* current = head;
    printf("Phone Directory:\n");
    while (current != NULL) {
        printf("Name: %s, Phone Number: %s\n", current->name, current->phone_number);
        current = current->next;
    }
}

void menu() {
    printf("\n-----------------------\n");
    printf("Phone Directory Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Display Contacts\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

int main() {
    Contact* head = NULL;
    int choice;
    char name[50], phone_number[20];

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone_number);
                addContact(&head, name, phone_number);
                printf("Contact added successfully.\n");
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(&head, name);
                printf("Contact deleted successfully.\n");
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                char* phone = searchContact(head, name);
                if (phone != NULL) {
                    printf("Phone number: %s\n", phone);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                displayContacts(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    // Free memory
    Contact* current = head;
    while (current != NULL) {
        Contact* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

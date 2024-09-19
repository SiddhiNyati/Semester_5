#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newnode = createNode(data);

    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = *head;
    }
}

void displayNode (struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    while (temp != head);
    printf("\n");
}

int main() {
    struct Node*head = NULL;

    insertNode(&head, 12);
    insertNode(&head, 13);
    insertNode(&head, 88);
    insertNode(&head, 99);

    displayNode(head);

    return 0;
}
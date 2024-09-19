#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void splitList(struct Node* head, struct Node** oddList, struct Node** evenList) {
    while (head != NULL) {
        if (head->data % 2 == 0) {
            insertAtEnd(evenList, head->data);
        } else {
            insertAtEnd(oddList, head->data);
        }
        head = head->next;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    char longInteger[1000]; 
    struct Node* head = NULL;
    struct Node* oddList = NULL;
    struct Node* evenList = NULL;

    printf("Enter a very long integer: ");
    scanf("%s", longInteger);

    for (int i = 0; longInteger[i] != '\0'; i++) {
        int digit = longInteger[i] - '0'; 
        insertAtEnd(&head, digit);
    }

    splitList(head, &oddList, &evenList);

    printf("Original list: ");
    printList(head);

    printf("Odd list: ");
    printList(oddList);

    printf("Even list: ");
    printList(evenList);

    return 0;
}
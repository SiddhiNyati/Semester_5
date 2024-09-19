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

struct Node* createList() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int i, data;

    for (i = 0; i < 5; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

int main() {
    struct Node* head = createList();
    displayList(head);

    int data;
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    head = insertNode(head, data);

    displayList(head);

    return 0;
}

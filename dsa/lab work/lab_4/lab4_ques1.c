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

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* insertAfterValue(struct Node* head, int x) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }
    if (temp != NULL) {
        struct Node* newNode = createNode(12);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Node with value %d not found.\n", x);
    }
    return head;
}

struct Node* insertBeforeValue(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL || head->data == 12) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != 12) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Node with value 12 not found.\n");
    }
    
    return head;
}

struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    } else {
        printf("Node with value %d not found.\n", data);
    }

    return head;
}

int main() {
    struct Node* head = createList();
    displayList(head);

    int data;

    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    head = insertAtBeginning(head, data);
    displayList(head);

    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    head = insertAtEnd(head, data);
    displayList(head);

    int x;
    printf("Enter the value of the node after which to insert 12: ");
    scanf("%d", &x);
    head = insertAfterValue(head, x);
    displayList(head);

    printf("Enter data to insert before the node with value 12: ");
    scanf("%d", &data);
    head = insertBeforeValue(head, data);
    displayList(head);

    printf("Enter data of the node to delete: ");
    scanf("%d", &data);
    head = deleteNode(head, data);
    displayList(head);

    return 0;
}
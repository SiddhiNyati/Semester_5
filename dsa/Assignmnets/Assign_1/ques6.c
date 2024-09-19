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

struct Node* swapPairs(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;  
    }

    struct Node* newHead = head->next;  
    struct Node* prev = NULL;

    while (head != NULL && head->next != NULL) {
        struct Node* first = head;
        struct Node* second = head->next;

        first->next = second->next;
        second->next = first;

        if (prev != NULL) {
            prev->next = second;
        }

        prev = first;
        head = first->next;
    }

    return newHead;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Original linked list: ");
    printList(head);

    head = swapPairs(head);

    printf("Linked list after swapping pairs: ");
    printList(head);

    return 0;
}
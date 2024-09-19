#include <stdio.h>
#include <stdlib.h>

struct Node {
    int serial_id;
    int episode_number;
    int customer_numbers[5];
    struct Node* next;
};

struct Node* createNode(int serial_id, int episode_number, int customer_numbers[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->serial_id = serial_id;
    newNode->episode_number = episode_number;
    for (int i = 0; i < 5; i++) {
        newNode->customer_numbers[i] = customer_numbers[i];
    }
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int serial_id, int episode_number, int customer_numbers[]) {
    struct Node* newNode = createNode(serial_id, episode_number, customer_numbers);
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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("Serial ID: %d, Episode Number: %d, Customer Numbers: ", head->serial_id, head->episode_number);
        for (int i = 0; i < 5; i++) {
            printf("%d ", head->customer_numbers[i]);
        }
        printf("\n");
        head = head->next;
    }
    printf("\n");
}

void rotateListClockwise(struct Node** head, int n) {
    if (*head == NULL || n == 0) {
        return;
    }

    struct Node* current = *head;
    int len = 1;
    while (current->next != NULL) {
        current = current->next;
        len++;
    }

    if (n >= len) {
        return;
    }

    current->next = *head;

    int steps = len - n;
    struct Node* newTail = *head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    *head = newTail->next;
    newTail->next = NULL;
}

void rotateListAntiClockwise(struct Node** head, int n) {
    if (*head == NULL || n == 0) {
        return;
    }

    struct Node* current = *head;
    int count = 1;

    while (count < n && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        return;
    }

    struct Node* nthNode = current;
    struct Node* newHead = nthNode->next;

    current = nthNode->next;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = *head;
    nthNode->next = NULL;
    *head = newHead;
}

int main() {
    struct Node* head = NULL;

    int customer_numbers1[5] = {1, 2, 3, 4, 5};
    int customer_numbers2[5] = {6, 7, 8, 9, 10};
    int customer_numbers3[5] = {11, 12, 13, 14, 15};
    int customer_numbers4[5] = {16, 17, 18, 19, 20};
    int customer_numbers5[5] = {21, 22, 23, 24, 25};
    int customer_numbers6[5] = {26, 27, 28, 29, 30};
    int customer_numbers7[5] = {31, 32, 33, 34, 35};
    int customer_numbers8[5] = {36, 37, 38, 39, 40};

    insertAtEnd(&head, 101, 1, customer_numbers1);
    insertAtEnd(&head, 102, 2, customer_numbers2);
    insertAtEnd(&head, 103, 3, customer_numbers3);
    insertAtEnd(&head, 104, 4, customer_numbers4);
    insertAtEnd(&head, 105, 5, customer_numbers5);
    insertAtEnd(&head, 106, 6, customer_numbers6);
    insertAtEnd(&head, 107, 7, customer_numbers7);
    insertAtEnd(&head, 108, 8, customer_numbers8);

    printf("Original list:\n");
    printList(head);

    int n = 4;

    rotateListClockwise(&head, n);
    printf("Rotated list clockwise from position %d:\n", n);
    printList(head);

    rotateListAntiClockwise(&head, n);
    printf("Rotated list anti-clockwise from position %d:\n", n);
    printList(head);

    return 0;
}
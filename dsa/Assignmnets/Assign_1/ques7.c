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

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* dummyNode = createNode(0);
    struct Node* tail = dummyNode;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    }

    if (list2 != NULL) {
        tail->next = list2;
    }

    struct Node* mergedList = dummyNode->next;
    free(dummyNode);
    return mergedList;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n1, n2, data;

    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n1);

    printf("Enter the elements of the first linked list (sorted): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        insertAtEnd(&list1, data);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);

    printf("Enter the elements of the second linked list (sorted): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        insertAtEnd(&list2, data);
    }

    printf("First linked list: ");
    printList(list1);

    printf("Second linked list: ");
    printList(list2);

    struct Node* mergedList = mergeLists(list1, list2);

    printf("Merged linked list: ");
    printList(mergedList);

    return 0;
}

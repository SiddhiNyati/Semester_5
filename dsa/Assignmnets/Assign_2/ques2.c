#include<stdio.h>
#include<stdlib.h>  

struct node {
    int data;
    struct node *next;
};
struct node *F, *R;

void enq(int Y, int Amb) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = Y;
    newNode->next = NULL;

    if (Amb) {
        newNode->next = F;
        F = newNode;
        if (R == NULL) {
            R = F;
        }
    } else {
        if (F == NULL) {
            F = R = newNode;
        } else {
            R->next = newNode;
            R = newNode;
        }
    }
}

int deq() {
    int X = -1;
    struct node *P;
    if (F == NULL) {
        printf("Queue is empty\n");
    } else {
        P = F;
        F = F->next;
        X = P->data;
        free(P);
        P = NULL;
    }
    return X;
}

void display() {
    if (F == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *P = F;
        while (P != NULL) {
            printf("%d ", P->data);  
            P = P->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, carNo;

    while (1) {  
        printf("\nMenu:\n");
        printf("1. Add a car \n");
        printf("2. Add an ambulance \n");
        printf("3. Dequeue a car\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);  

        switch(choice) {
            case 1:
                printf("Enter car number: ");
                scanf("%d", &carNo);  
                enq(carNo, 0); //normal car
                break;

            case 2:
                printf("Enter ambulance number: ");
                scanf("%d", &carNo); 
                enq(carNo, 1);  //ambulance
                break;

            case 3:
                carNo = deq();
                if (carNo != -1) {
                    printf("Dequeued car/ambulance number: %d\n", carNo);
                }
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting\n");
                exit(0);  

            default:
                printf("Invalid choice\n");
        }
    }
}
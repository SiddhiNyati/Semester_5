#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int priority;
};

struct PriorityQueue {
    struct Process processes[100]; 
    int size; 
};

void insertProcess(struct PriorityQueue* pq) {
    struct Process newProcess;
    printf("Enter process ID: ");
    scanf("%d", &newProcess.id);
    printf("Enter priority: ");
    scanf("%d", &newProcess.priority);
    
    pq->processes[pq->size] = newProcess; 
    pq->size++; 
    printf("Process with ID %d inserted with priority %d\n", newProcess.id, newProcess.priority);
}

void deleteProcess(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty. Nothing to delete.\n");
        return;
    }
    
    int maxPriorityIndex = 0;
    
    for (int i = 1; i < pq->size; i++) {
        if (pq->processes[i].priority > pq->processes[maxPriorityIndex].priority) {
            maxPriorityIndex = i;
        }
    }

    struct Process deletedProcess = pq->processes[maxPriorityIndex];
    
    for (int i = maxPriorityIndex; i < pq->size - 1; i++) {
        pq->processes[i] = pq->processes[i + 1];
    }
    
    pq->size--; 
    printf("Process with ID %d and priority %d deleted.\n", deletedProcess.id, deletedProcess.priority);
}

void displayProcesses(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Processes in the queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("ID: %d, Priority: %d\n", pq->processes[i].id, pq->processes[i].priority);
    }
}

int main() {
    struct PriorityQueue pq;
    pq.size = 0; 
    
    while (1) {
        int choice;
        printf("\nChoose an operation:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertProcess(&pq);
                break;
            case 2:
                deleteProcess(&pq);
                break;
            case 3:
                displayProcesses(&pq);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    
    return 0;
}
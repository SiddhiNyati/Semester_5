#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Song {
    int songID;
    char songName[100];
    struct Song *next;
} Song;
Song* insertAtBeginning(Song *head, int songID, char *songName) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    newSong->songID = songID;
    strcpy(newSong->songName, songName);
    newSong->next = head;
    return newSong;
}

Song* insertAtEnd(Song *head, int songID, char *songName) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    newSong->songID = songID;
    strcpy(newSong->songName, songName);
    newSong->next = NULL;

    if (head == NULL) {
        return newSong;
    }

    Song *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newSong;
    return head;
}

Song* insertAfter(Song *head, int songID, char *songName, int x) {
    Song *temp = head;
    while (temp != NULL && temp->songID != x) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song ID %d not found.\n", x);
        return head;
    }

    Song *newSong = (Song *)malloc(sizeof(Song));
    newSong->songID = songID;
    strcpy(newSong->songName, songName);
    newSong->next = temp->next;
    temp->next = newSong;
    return head;
}

Song* insertBefore(Song *head, int songID, char *songName, int x) {
    if (head == NULL) {
        return NULL;
    }

    if (head->songID == x) {
        return insertAtBeginning(head, songID, songName);
    }

    Song *temp = head;
    while (temp->next != NULL && temp->next->songID != x) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Song ID %d not found.\n", x);
        return head;
    }

    Song *newSong = (Song *)malloc(sizeof(Song));
    newSong->songID = songID;
    strcpy(newSong->songName, songName);
    newSong->next = temp->next;
    temp->next = newSong;
    return head;
}

void printList(Song *head) {
    Song *temp = head;
    while (temp != NULL) {
        printf("Song ID: %d, Song Name: %s\n", temp->songID, temp->songName);
        temp = temp->next;
    }
}


void searchSong(Song *head, char *songName) {
    Song *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->songName, songName) == 0) {
            printf("Song found: ID = %d, Name = %s\n", temp->songID, temp->songName);
            return;
        }
        temp = temp->next;
    }
    printf("Song not found.\n");
}


void printReverse(Song *head) {
    if (head == NULL) {
        return;
    }
    printReverse(head->next);
    printf("Song ID: %d, Song Name: %s\n", head->songID, head->songName);
}


int countIterative(Song *head) {
    int count = 0;
    Song *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


int countRecursive(Song *head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + countRecursive(head->next);
}


Song* deleteSongByID(Song *head, int songID) {
    if (head == NULL) {
        return NULL;
    }

    if (head->songID == songID) {
        Song *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Song *temp = head;
    while (temp->next != NULL && temp->next->songID != songID) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Song ID %d not found.\n", songID);
        return head;
    }

    Song *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}


Song* deleteLast(Song *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Song *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}


Song* deleteFirst(Song *head) {
    if (head == NULL) {
        return NULL;
    }

    Song *temp = head;
    head = head->next;
    free(temp);
    return head;
}


Song* deleteAllIterative(Song *head) {
    Song *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}


Song* deleteAllRecursive(Song *head) {
    if (head == NULL) {
        return NULL;
    }
    deleteAllRecursive(head->next);
    free(head);
    return NULL;
}

int main() {
    Song *head = NULL;
    int choice, songID, x;
    char songName[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after song ID\n");
        printf("4. Insert before song ID\n");
        printf("5. Print list\n");
        printf("6. Search song by name\n");
        printf("7. Print list in reverse\n");
        printf("8. Count elements (iterative)\n");
        printf("9. Count elements (recursive)\n");
        printf("10. Delete by song ID\n");
        printf("11. Delete last song\n");
        printf("12. Delete first song\n");
        printf("13. Delete all songs (iterative)\n");
        printf("14. Delete all songs (recursive)\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song ID: ");
                scanf("%d", &songID);
                printf("Enter song name: ");
                scanf(" %[^\n]s", songName);
                head = insertAtBeginning(head, songID, songName);
                break;
            case 2:
                printf("Enter song ID: ");
                scanf("%d", &songID);
                printf("Enter song name: ");
                scanf(" %[^\n]s", songName);
                head = insertAtEnd(head, songID, songName);
                break;
            case 3:
                printf("Enter song ID to insert after: ");
                scanf("%d", &x);
                printf("Enter new song ID: ");
                scanf("%d", &songID);
                printf("Enter song name: ");
                scanf(" %[^\n]s", songName);
                head = insertAfter(head, songID, songName, x);
                break;
            case 4:
                printf("Enter song ID to insert before: ");
                scanf("%d", &x);
                printf("Enter new song ID: ");
                scanf("%d", &songID);
                printf("Enter song name: ");
                scanf(" %[^\n]s", songName);
                head = insertBefore(head, songID, songName, x);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                printf("Enter song name to search: ");
                scanf(" %[^\n]s", songName);
                searchSong(head, songName);
                break;
            case 7:
                printReverse(head);
                break;
            case 8:
                printf("Number of songs: %d\n", countIterative(head));
                break;
            case 9:
                printf("Number of songs: %d\n", countRecursive(head));
                break;
            case 10:
                printf("Enter song ID to delete: ");
                scanf("%d", &songID);
                head = deleteSongByID(head, songID);
                break;
            case 11:
                head = deleteLast(head);
                break;
            case 12:
                head = deleteFirst(head);
                break;
            case 13:
                head = deleteAllIterative(head);
                break;
            case 14:
                head = deleteAllRecursive(head);
                break;
            case 15:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP_READINGS 3

typedef struct {
    char city[50];
    char date[11];
    float temperatures[MAX_TEMP_READINGS];
} TemperatureData;
void createArray(TemperatureData **arr, int *size) {
    *size = 2; 
    *arr = malloc(*size * sizeof(TemperatureData));
    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    
    strcpy((*arr)[0].city, "CityA");
    strcpy((*arr)[0].date, "2024-09-09");
    for (int i = 0; i < MAX_TEMP_READINGS; i++) {
        (*arr)[0].temperatures[i] = 20.0 + i;
    }

    strcpy((*arr)[1].city, "CityB");
    strcpy((*arr)[1].date, "2024-09-10");
    for (int i = 0; i < MAX_TEMP_READINGS; i++) {
        (*arr)[1].temperatures[i] = 15.0 + i;
    }
}
void insertElement(TemperatureData **arr, int *size, TemperatureData newElement, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    (*size)++;
    *arr = realloc(*arr, (*size) * sizeof(TemperatureData));
    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
  
    for (int i = *size - 1; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
   
    (*arr)[position] = newElement;
}
void printArray(TemperatureData *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("City: %s\n", arr[i].city);
        printf("Date: %s\n", arr[i].date);
        printf("Temperatures: ");
        for (int j = 0; j < MAX_TEMP_READINGS; j++) {
            printf("%.2f ", arr[i].temperatures[j]);
        }
        printf("\n");
    }
}
void printArrayReverse(TemperatureData *arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("City: %s\n", arr[i].city);
        printf("Date: %s\n", arr[i].date);
        printf("Temperatures: ");
        for (int j = 0; j < MAX_TEMP_READINGS; j++) {
            printf("%.2f ", arr[i].temperatures[j]);
        }
        printf("\n");
    }
}

int searchCity(TemperatureData *arr, int size, const char *city) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].city, city) == 0) {
            return i;
        }
    }
    return -1; // Not found
}
void printElement(TemperatureData *data) {
    printf("City: %s\n", data->city);
    printf("Date: %s\n", data->date);
    printf("Temperatures: ");
    for (int j = 0; j < MAX_TEMP_READINGS; j++) {
        printf("%.2f ", data->temperatures[j]);
    }
    printf("\n");
}

void deleteElement(TemperatureData **arr, int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
 
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    
    (*size)--;
    *arr = realloc(*arr, (*size) * sizeof(TemperatureData));
    if (*arr == NULL && *size > 0) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}
int main() {
    int size;
    TemperatureData *arr = NULL;
    int choice, position;
    TemperatureData newElement;
    char cityToSearch[50];
    createArray(&arr, &size);
    do {
        printf("\nMenu:\n");
        printf("1. Insert new element\n");
        printf("2. Search for a city\n");
        printf("3. Print the entire array\n");
        printf("4. Print the entire array in reverse direction\n");
        printf("5. Delete an element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter city: ");
                scanf("%s", newElement.city);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", newElement.date);
                printf("Enter 24 temperature readings (one per hour): ");
                for (int i = 0; i < MAX_TEMP_READINGS; i++) {
                    scanf("%f", &newElement.temperatures[i]);
                }
                printf("Enter position to insert the element: ");
                scanf("%d", &position);
                insertElement(&arr, &size, newElement, position);
                printf("Element inserted successfully.\n");
                break;

            case 2:
                printf("Enter city to search: ");
                scanf("%s", cityToSearch);
                int index = searchCity(arr, size, cityToSearch);
                if (index != -1) {
                    printf("City found at index %d:\n", index);
                    printElement(&arr[index]);
                } else {
                    printf("City not found.\n");
                }
                break;

            case 3:
                printArray(arr, size);
                break;

            case 4:
                printArrayReverse(arr, size);
                break;

            case 5:
                printf("Enter position to delete the element: ");
                scanf("%d", &position);
                deleteElement(&arr, &size, position);
                printf("Element deleted successfully.\n");
                break;

            case 6:
                free(arr);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
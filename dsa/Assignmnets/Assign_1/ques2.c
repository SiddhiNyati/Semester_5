#include <stdio.h>

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int mergedArray[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        mergedArray[k++] = arr1[i++];
    }

    while (j < n2) {
        mergedArray[k++] = arr2[j++];
    }
}

int main() {
    int n1, n2;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter the elements of the first array (sorted): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter the elements of the second array (sorted): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("First array: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Second array: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    int mergedArray[n1 + n2];

    mergeArrays(arr1, n1, arr2, n2, mergedArray);

    printf("Merged array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}

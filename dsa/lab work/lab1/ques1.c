#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);
    int sum = 0;
    
    int *ptr = array;

    for (int i = 0; i < length; i++) {
        sum += *(ptr + i);
    }
    printf("Sum of all elements: %d\n", sum);
    
    return 0;
}
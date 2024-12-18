#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    char author[100];
    float price;
} Book;

void printBookDetails(Book *books, int n) {
    for (int i = 0; i < n; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Price: %.2f\n", books[i].price);
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    Book *books = (Book *)malloc(n * sizeof(Book));
    if (books == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]%*c", books[i].title); 
        printf("Author: ");
        scanf(" %[^\n]%*c", books[i].author); 
        printf("Price: ");
        scanf("%f", &books[i].price);
        printf("\n");
    }
    printBookDetails(books, n);

    free(books);

    return 0;
}
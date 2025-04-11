// Name:        J-D-J123
// Date:        4/11/2025
// Class:       cs2050 
// Desc:        Book catalog implemntation 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long ISBN; // International Standard Book Number
    int bookID; // Unique internal book identifier
    char *title; // Dyamically allocated string for the book title
} Book; 

// -------------- BookCatalog structure ---------------- //
typedef struct {
    Book **byISBN; 
    Book **byID; 
    int numBooks; 
    int errorCode; 
} BookCatalog; 

// functions to implement 
BookCatalog createSearchableBookCatalog(Book **, int);
Book * findBookByISBN(long long, BookCatalog); 
Book * findBookByID(int, BookCatalog); 
void freeBookCatalog(BookCatalog); 
int getBookErrorCode(BookCatalog); 

// added helpers 
void bubbleSortByISBN(Book **books, int numBooks);
void bubbleSortByID(Book **books, int numBooks);

// -------------- Helper functions ----------------------------- // 
void bubbleSortByISBN(Book **books, int numBooks) {
    for (int i = 0; i < numBooks - 1; i++) {
        for (int j = 0; j < numBooks - i - 1; j++) {
            if (books[j]->ISBN > books[j + 1]->ISBN) {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void bubbleSortByID(Book **books, int numBooks) {
    for (int i = 0; i < numBooks - 1; i++) {
        for(int j = 0; j < numBooks - i - 1; j++) {
            if (books[j]->bookID > books[j + 1]->bookID) {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

// -------------- BookCatalog creation function ---------------- // 
// returns 1 if error and 0 if no error 
BookCatalog createSearchableBookCatalog(Book **books, int numBooks) {
    BookCatalog catalog = {NULL, NULL, numBooks, 0};

    if(numBooks <= 0 || books == NULL) {
        catalog.errorCode = 1; 
        return catalog; 
    }

    // create multiple sizes for the array 
    catalog.byISBN = (Book **)malloc(numBooks * sizeof(Book *));
    catalog.byID = (Book **)malloc(numBooks * sizeof(Book *));

    if(!catalog.byISBN || !catalog.byID) {
        catalog.errorCode = 1; 
        return catalog; 
    }

    for (int i = 0; i < numBooks; i++) {
        catalog.byISBN[i] = books[i];
        catalog.byID[i] = books[i];
    }
    

    // sort the catalog by using a helper method of bubble sort 
    bubbleSortByISBN(catalog.byISBN, numBooks); 
    bubbleSortByID(catalog.byID, numBooks);

    // return sorted array 
    return catalog; 
}

// -------------- Book search by ISBN function ---------------- //
Book *findBookByISBN(long long ISBN, BookCatalog catalog) {
    if (catalog.byISBN == NULL || catalog.numBooks <= 0) {
        catalog.errorCode = 1; 
        return NULL; 
    }

    // ISBN has to be greater than 0 
    if (ISBN < 0) {
        catalog.errorCode = 1; 
        return NULL; 
    }

    // binary search 
    int left = 0; 
    int right = catalog.numBooks - 1; 

    while(left <= right) {
        int mid = (left + right) / 2; 
        long long midISBN = catalog.byISBN[mid]->ISBN; 

        if (midISBN == ISBN) {
            catalog.errorCode = 0; 
            return catalog.byISBN[mid];
        } else if (midISBN < ISBN) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // else book not found 
    catalog.errorCode = 1;         
    return NULL; 
}

Book *findBookByID(int ID, BookCatalog catalog) {
    if (catalog.byID == NULL || catalog.numBooks <= 0) {
        catalog.errorCode = 1; 
        return NULL; 
    }

    // ISBN has to be greater than 0 
    if (ID < 0) {
        catalog.errorCode = 1; 
        return NULL; 
    }

    // binary search 
    int left = 0; 
    int right = catalog.numBooks - 1; 

    while(left <= right) {
        int mid = (left + right) / 2; 
        int midID = catalog.byID[mid]->bookID; 

        if (midID == ID) {
            catalog.errorCode = 0; 
            return catalog.byID[mid];
        } else if (midID < ID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // else book not found 
    catalog.errorCode = 1;         
    return NULL; 
}

void freeBookCatalog(BookCatalog catalog) {
    if (catalog.byISBN != NULL) {
        free(catalog.byISBN);
    }
    if (catalog.byID != NULL) {
        free(catalog.byID);
    }
}

// ChatGPT created the main function 
int main() {

    // Create a few books 
    Book book1 = {9780131103627, 1, "The C Programming Language"};
    Book book2 = {9780131101630, 2, "Introduction to Algorithms"};
    Book book3 = {9780131103628, 3, "Computer Networks"};

    // Dynamically allocate memory for the titles
    book1.title = (char *)malloc(strlen(book1.title) + 1);
    strcpy(book1.title, "The C Programming Language");
    
    book2.title = (char *)malloc(strlen(book2.title) + 1);
    strcpy(book2.title, "Introduction to Algorithms");
    
    book3.title = (char *)malloc(strlen(book3.title) + 1);
    strcpy(book3.title, "Computer Networks");

    // Create an array of pointers to books
    Book *books[] = {&book1, &book2, &book3};
    
    // Create a searchable book catalog
    BookCatalog catalog = createSearchableBookCatalog(books, 3);

    // Search for a book by ISBN
    Book *foundBookByISBN = findBookByISBN(9780131103627, catalog);
    if (foundBookByISBN != NULL) {
        printf("Found book by ISBN: %s\n", foundBookByISBN->title);
    } else {
        printf("Book not found by ISBN.\n");
    }

    // Search for a book by ID
    Book *foundBookByID = findBookByID(2, catalog);
    if (foundBookByID != NULL) {
        printf("Found book by ID: %s, \n ISBN: %lld\n", foundBookByID->title, foundBookByID->ISBN);
    } else {
        printf("Book not found by ID.\n");
    }

    // Free the book catalog
    freeBookCatalog(catalog);

    // Free dynamically allocated titles
    free(book1.title);
    free(book2.title);
    free(book3.title);

    return 0;
} // end of prelab9.c

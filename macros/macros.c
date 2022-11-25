#include "stdio.h"

typedef unsigned char INT_1;

// Constant
#define LIMIT 4

// Function to compute area
#define AREA(l, b) (l * b)

// Multi line list almost
#define ELEMENTS 1, \
                 2, \
                 3

#define CONCAT(a, b) a##b  // Hashes between concatenates it

#define STR(a) #a // Hash before converts to string


int main() {
    printf("Limit is %d\n", LIMIT);

    printf("Area is %d\n", AREA(11, 5));

    // Array has elements 1, 2, 3
    int arr[] = {ELEMENTS};
    printf("Macro element array: ");
    for(INT_1 i=0;i<3;i++)
        printf("%d", arr[i]);

    printf("\nConcatenation: %d\n", CONCAT(12, 34)); // prints 1234.

    int x = 3245;
    printf("To string: %d, %s\n", x, STR(x));


}

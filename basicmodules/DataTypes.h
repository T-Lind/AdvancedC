#include <stdio.h>

void datatypes() {
    short shortInteger = 10000; // 2 bytes, max is 32,767 signed %hd
    int integer = 2000000000; // 4 bytes, max is 2,147,483,647 signed %d
    long longInteger = 1234567890; // 4 bytes, %ld
    long long veryLongInt = 1234567890123456789; // 8 bytes, %lld
    char character = 'C'; // Character, 1 byte, %c
    float floating = 3.14159f; // 4 bytes, accurate to 6 decimals, %f
    double doubleFloating = 2.718281828459045; // 8 bytes, accurate to 15 decimals, %lf
    char str[] = "Hello world!"; // length of char[] array is actually letters + 1, \0 terminating char is added, %s

    printf("DATATYPES:\n");
    printf("Example of long long: %lld with size of %d bytes\n\n", veryLongInt, sizeof(veryLongInt));
}
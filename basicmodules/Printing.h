#include <stdio.h>

void printing(){
    printf("PRINTING:\n");

    char message[] = "Hello World!\n";
    printf("%s", message);

    int fingers = 8;
    double height = 1.45;
    printf("You have %i fingers and are %.2fm tall\n", fingers, height);

    printf("Other printing: pointer: 0x%p, char: %c\n\n", &fingers, 'A');
}
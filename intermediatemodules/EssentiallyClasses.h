#include "stdio.h"

struct Dog {
    unsigned char age;
    char* name;

    void (*bark)();

};

void bark(){
    printf("Woof woof!\n");
}

// Remove the struct from the declaration
typedef struct Dog Dog;

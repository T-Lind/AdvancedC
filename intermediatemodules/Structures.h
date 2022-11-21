#include <stdio.h>

struct Person {
    char *name;
    int age;
};

void structures() {
    printf("STRUCTURES:\n");

    struct Person person1;
    person1.name = "Timothy"; // This is allowed! Could also create a char array and pass it.
    person1.age = 23;

    printf("Example of a struct: %s is %d years old.\n", person1.name, person1.age);

    struct Person person2 = {"Anthony", 53}; // Also defines a structure

    person1 = person2; // Deep copy!
    person2.name = "Bill";
    printf("Example of struct reassignments: %s is %d years old.\n\n", person1.name, person1.age);
}
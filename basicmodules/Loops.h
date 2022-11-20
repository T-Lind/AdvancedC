#include <stdio.h>
#include "Arrays.h"

void loops() {
    printf("LOOPS:\n");

    int array[] = {4, 7, 3, 1, -50, 95, 3, 0};
    int len = sizeof(array) / sizeof(array[0]);

    // Insertion sort
    int i, key, j;
    for (i = 1; i < len; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    printf("Sorting an array through insertion sort: ");
    printArrayInt(array, len);
    printf("\n");
}

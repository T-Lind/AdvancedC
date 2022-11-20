#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p, const void *q){
    int l = *(const int *)p;
    int r = *(const int *)q;

    if ((l&1) && (r&1))
        return (r-l);
    if ( !(l&1) && !(r&1) )
        return (l-r);
    if (!(l&1))
        return 1;
    return -1;
}

void printArrayDouble(double* array, int size){
    printf("[");
    for(int i=0;i<size-1;i++){
        printf("%.3f, ", array[i]);
    }
    printf("%f]\n", array[size-1]);
}

void printArrayInt(int* array, int size){
    printf("[");
    for(int i=0;i<size-1;i++){
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size-1]);
}

void arrays(){
    printf("ARRAYS:\n");

    // Normal statically allocated arrays:
    int array1[10]; // Assigns array1 with 10 int items of RANDOM MEMORY
    float array2[10]; // Assigns array2 with 10 float items of RANDOM MEMORY
    double array3[] = {0.1, 0.001, 0.0001, 0.00001, 0.0001, 0.001, 0.01, 0.1}; // Assigns array3 filled with items
    int array3size = sizeof(array3) / sizeof(array3[0]);

    printf("Original array: ");
    printArrayDouble(array3, array3size);
    qsort((void*)array3, array3size, sizeof(array3[0]), comparator);
    printf("Sorted array: ");
    printArrayDouble(array3, array3size);

    int array4[3][3]; // 2d array 3x3 of RANDOM MEMORY
    long array5[][3] = { // Notice we must specify the 2nd array3size but not the first!
            {102, 34, 39},
            {99, -1389, 9999},
            {7754, -1335, -5978}}; // 2d array already filled in

    printf("Example: array5 [2][1] = %ld\n", array5[2][1]);

    // Dynamically allocated arrays:
    int fibListLen = 15;

    // Allocate memory for the fibList
    int* fibList = (int*)malloc(fibListLen * sizeof(int));
    if(fibList == NULL){
        printf("Memory not allocated!");
    }
    else {
        fibList[0] = 1;
        fibList[1] = 1;
        for(int i=2; i < fibListLen; i++)
            fibList[i] = fibList[i - 1] + fibList[i - 2];

        printf("First few elements of the fibbonaci sequence (dynamic array): ");
        printArrayInt(fibList, fibListLen);

        // Free dynamic memory
        free(fibList);
    }
}
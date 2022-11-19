#include <stdio.h>

void arrays(){
    // Normal statically assigned array:
    int array1[10]; // Assigns array1 with 10 int items of RANDOM MEMORY
    float array2[10]; // Assigns array2 with 10 float items of RANDOM MEMORY
    double array3[] = {0.1, 0.001, 0.0001, 0.00001, 0.0001, 0.001, 0.01, 0.1}; // Assigns array3 filled with items

    int array4[3][3]; // 2d array 3x3 of RANDOM MEMORY
    long array5[][3] = { // Notice we must specify the 2nd size but not the first!
            {102, 34, 39},
            {99, -1389, 9999},
            {7754, -1335, -5978}}; // 2d array already filled in

    
}
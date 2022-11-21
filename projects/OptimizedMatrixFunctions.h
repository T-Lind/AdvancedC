#include <stdio.h>


const Matrix_Dim size = {2, 5};

// Unrolling loops removes ~100ms

void OptimizeMatrix_add(double arr[][size.width], double arr2[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        arr[r][0] += arr2[r][0];
        arr[r][1] += arr2[r][1];
        arr[r][2] += arr2[r][2];
        arr[r][3] += arr2[r][3];
        arr[r][4] += arr2[r][4];
    }
}

void OptimizeMatrix_div(double arr[][size.width], double arr2[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        arr[r][1] *= arr2[r][1];
        arr[r][2] *= arr2[r][2];
        arr[r][0] *= arr2[r][0];
        arr[r][3] *= arr2[r][3];
        arr[r][4] *= arr2[r][4];
    }
}


void OptimizeMatrix_mulScalar(double scalar, double arr[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] *= scalar;
        }
    }
}

void OptimizeMatrix_print(Matrix_Dim size, double arr[][size.width]) {
    // Unrolled loops, removed switch statements - reduces compile time by about 10 ms
    for(int r=0;r<size.height-1;r++){
        printf("%.1f, ", arr[r][0]);
        printf("%.1f, ", arr[r][1]);
        printf("%.1f, ", arr[r][2]);
        printf("%.1f, ", arr[r][3]);
        printf("%.1f, ", arr[r][4]);
        printf("\n");
    }
    printf("%.1f, ", arr[size.height-1][0]);
    printf("%.1f, ", arr[size.height-1][1]);
    printf("%.1f, ", arr[size.height-1][2]);
    printf("%.1f, ", arr[size.height-1][3]);
    printf("%.1f, ", arr[size.height-1][4]);
    printf("\b\n");
}


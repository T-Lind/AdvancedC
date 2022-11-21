#include <stdio.h>

struct Matrix_Dim {
    int height, width;
};
typedef struct Matrix_Dim Matrix_Dim;

void Matrix_add(Matrix_Dim size, double arr[][size.width], double arr2[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] += arr2[r][c];
        }
    }
}

void Matrix_sub(Matrix_Dim size, double arr[][size.width], double arr2[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] -= arr2[r][c];
        }
    }
}

void Matrix_mul(Matrix_Dim size, double arr[][size.width], double arr2[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] *= arr2[r][c];
        }
    }
}

void Matrix_addScalar(Matrix_Dim size, double arr[][size.width], double arr2[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] += arr2[r][c];
        }
    }
}

void Matrix_subScalar(Matrix_Dim size, double arr[][size.width], double arr2[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] -= arr2[r][c];
        }
    }
}

void Matrix_div(Matrix_Dim size, double arr[][size.width], double arr2[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] /= arr2[r][c];
        }
    }
}

double Matrix_dotProduct(Matrix_Dim size, double arr[][size.width], double arr2[][size.width]) {
    double sum = 0;
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            sum += arr[r][c] * arr2[r][c];
        }
    }
    return sum;
}

void Matrix_mulScalar(Matrix_Dim size, double scalar, double arr[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] *= scalar;
        }
    }
}

void Matrix_divScalar(Matrix_Dim size, double scalar, double arr[][size.width]) {
    for (int r = 0; r < size.height; r++) {
        for (int c = 0; c < size.width; c++) {
            arr[r][c] /= scalar;
        }
    }
}

void Matrix_switchRows(Matrix_Dim size, int rowOneSwitch, int rowTwoSwitch, double arr[][size.width]) {
    for(int c=0;c<size.width;c++){
        double rowOneVal = arr[rowOneSwitch][c];
        arr[rowOneSwitch][c] = arr[rowTwoSwitch][c];
        arr[rowTwoSwitch][c] = rowOneVal;
    }
}

void Matrix_addRows(Matrix_Dim size, int rowOneAdd, int rowTwoAdd, double arr[][size.width]) {
    for(int c=0;c<size.width;c++){
        arr[rowTwoAdd][c] += arr[rowOneAdd][c];
    }
}

void Matrix_subRows(Matrix_Dim size, int rowOneAdd, int rowTwoAdd, double arr[][size.width]) {
    for(int c=0;c<size.width;c++){
        arr[rowTwoAdd][c] -= arr[rowOneAdd][c];
    }
}

void Matrix_print(Matrix_Dim size, double arr[][size.width], int decimalPrecision) {
    printf("[");
    for(int r=0;r<size.height-1;r++){
        printf("[");
        for(int c=0;c<size.width;c++){
            switch(decimalPrecision){
                case 0:
                    printf("%.0f, ", arr[r][c]);
                    break;
                case 1:
                    printf("%.1f, ", arr[r][c]);
                    break;
                case 2:
                    printf("%.2f, ", arr[r][c]);
                    break;
                case 3:
                    printf("%.3f, ", arr[r][c]);
                    break;
                case 4:
                    printf("%.4f, ", arr[r][c]);
                    break;
                default:
                    printf("%f, ", arr[r][c]);
                    break;
            }
        }
        printf("\b],\n");
    }
    printf("[");
    for(int c=0;c<size.width;c++){
        switch(decimalPrecision){
            case 0:
                printf("%.0f, ", arr[size.height-1][c]);
                break;
            case 1:
                printf("%.1f, ", arr[size.height-1][c]);
                break;
            case 2:
                printf("%.2f, ", arr[size.height-1][c]);
                break;
            case 3:
                printf("%.3f, ", arr[size.height-1][c]);
                break;
            case 4:
                printf("%.4f, ", arr[size.height-1][c]);
                break;
            default:
                printf("%f, ", arr[size.height-1][c]);
                break;
        }
    }
    printf("\b\b]]\n");
}

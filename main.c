#include "basicmodules/Printing.h"
#include "basicmodules/DataTypes.h"
#include "basicmodules/Strings.h"
#include "basicmodules/Loops.h"
#include "intermediatemodules/Functions.h"
#include "intermediatemodules/Structures.h"
// Do not include Arrays.h, included through Loops.h
#include "projects/PostfixCalculator.h"
#include "projects/Tictactoe.h"
#include "projects/MatrixFunctions.h"
#include "time.h"
#include "projects/OptimizedMatrixFunctions.h"
#include "projects/VisionCalculations.h"
int main() {
    printing();
    datatypes();
    arrays();
    strings();
    loops();

    functions();
    structures();

    // Test postfix calculator
    printf("POSTFIX CALCULATOR:\n");
    char equation1[] = "27+12-+";
    printf("Result of %s : %d\n\n", equation1, calculate(equation1));

//    playTictactoe();

    // Regular matrix operations

    printf("MATRIX OPERATIONS:\n");
    const Matrix_Dim size = {2, 5};
    double table[][5] = {{3, 4, 5, 21, -4}, {9, -49, 104, 1, 0}};
    double tableTwo[][5] = {{9, -4, 50, 1, -14}, {-39, -9, 4, -1, 10}};

    int numTrials = 10000000;
    long long int before, after;
    before = clock();
    for(int i=0;i<numTrials;i++)
        Matrix_mulScalar(size, 1+1E-11, table);
    after = clock();
    printf("Multiply scalar time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    before = clock();
    for(int i=0;i<numTrials;i++)
        Matrix_div(size, table, tableTwo);
    after = clock();
    printf("Divide time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    before = clock();
    for(int i=0;i<numTrials;i++)
        Matrix_add(size, table, tableTwo);
    after = clock();
    printf("Add time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    before = clock();
    Matrix_print(size, table, 1);
    after = clock();
    printf("Print time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    printf("\n");

    // Optimized array functions

    printf("OPTIMIZED MATRIX OPERATIONS:\n");

    double tableB[][5] = {{3, 4, 5, 21, -4}, {9, -49, 104, 1, 0}};
    double tableTwoB[][5] = {{9, -4, 50, 1, -14}, {-39, -9, 4, -1, 10}};

    before = clock();
    for(int i=0;i<numTrials;i++)
        OptimizeMatrix_mulScalar(1+1E-11, tableB);
    after = clock();
    printf("Multiply scalar time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    before = clock();
    for(int i=0;i<numTrials;i++)
        OptimizeMatrix_div(tableB, tableTwoB);
    after = clock();
    printf("Divide time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    before = clock();
    for(int i=0;i<numTrials;i++)
        OptimizeMatrix_add(tableB, tableTwoB);
    after = clock();
    printf("Add time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    before = clock();
    OptimizeMatrix_print(size, tableB);
    after = clock();
    printf("Print time: %.0f milliseconds\n\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    printf("OPTIMIZING VISION MATH:\n");

    before = clock();
    for(int i=0;i<numTrials;i++)
        calculateCoordX(3, 4.5, 0.034);
    after = clock();
    printf("Non-optimized X calculate time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);
    before = clock();
    for(int i=0;i<numTrials;i++)
        calculateCoordY(3, 4.5, 0.034);
    after = clock();
    printf("Non-optimized Y calculate time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    before = clock();
    for(int i=0;i<numTrials;i++)
        calculateEfficientCoordX(3, 4.5, 0.034);
    after = clock();
    printf("Optimized X calculate time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);
    before = clock();
    for(int i=0;i<numTrials;i++)
        calculateEfficientCoordY(4.5, 0.034);
    after = clock();
    printf("Optimized Y calculate time: %.0f milliseconds\n", 1000.0*(after-before)/CLOCKS_PER_SEC);

    return 0;
}

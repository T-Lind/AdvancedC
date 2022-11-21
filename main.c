#include "basicmodules/Printing.h"
#include "basicmodules/DataTypes.h"
#include "basicmodules/Strings.h"
#include "basicmodules/Loops.h"
#include "Functions.h"
#include "Structures.h"
// Do not include Arrays.h, included through Loops.h
#include "projects/PostfixCalculator.h"
#include "projects/Tictactoe.h"
#include "projects/MatrixFunctions.h"

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

    printf("MATRIX OPERATIONS:\n");
    const Matrix_Dim size = {2, 5};
    double table[][5] = {{3, 4, 5, 21, -4}, {9, -49, 104, 1, 0}};
    double tableTwo[][5] = {{9, -4, 50, 1, -14}, {-39, -9, 4, -1, 10}};

    Matrix_add(size, table, tableTwo);
    Matrix_mulScalar(size, 3.4, table);
    Matrix_div(size, table, tableTwo);

    Matrix_print(size, table, 1);
    printf("\n");

    return 0;
}

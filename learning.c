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

    scanf("%hd", NULL);

    return 0;
}

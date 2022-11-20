#include "basicmodules/Printing.h"
#include "basicmodules/DataTypes.h"
#include "basicmodules/Strings.h"
#include "basicmodules/Loops.h"
#include "Functions.h"
#include "Structures.h"
// Do not include Arrays.h, included through Loops.h
#include "projects/PostfixCalculator.h"

int main() {
    printing();
    datatypes();
    arrays();
    strings();
    loops();

    functions();
    structures();

    // Test postfix calculator
    char equation1[] = "27+12-+";
    printf("Result of %s : %d\n", equation1, calculate(equation1));

    return 0;
}

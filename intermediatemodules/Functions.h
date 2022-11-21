#include <stdio.h>
#include <math.h>

typedef double (*ptr)(double*);
typedef ptr (*pm)();

double cube(double input) {return pow(input, 3);}

double cubePtr(double* input){return pow(*input, 3);}

ptr insertPrinting() {
    printf("Cubing output: ");
    return &cubePtr;
}

/**
 * Passing a function f as an input and nest it twice
 * Function takes a double as an input and passes a double
 * as an output.
 * @param f the function passed in
 * @param input the integer input to pass in
 * @return the result from running the nested function twice.
 */
double repeatFuncOut(double (*f)(double), int input) {
    return f(f(input));
}

void functions(){
    printf("FUNCTIONS:\n");
    printf("Repeated input: %.2f\n", repeatFuncOut(cube, 2));

    double a = 3;
    pm u = insertPrinting;
    double (*(*p[1])())(double*) = { u };
    printf("%.2f\n", (*p[0]())(&a));
}

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

// Create a stack
#define SIZE 10
int Top = -1;
int inp_array[SIZE];


// Stack operation - push an item in
void push(int x) {

    if (Top == SIZE - 1) {
        printf("\nOverflow!!\n");
    } else {
        Top = Top + 1;
        inp_array[Top] = x-48;
    }
}
void pushRefined(int x) {

    if (Top == SIZE - 1) {
        printf("\nOverflow!!\n");
    } else {
        Top = Top + 1;
        inp_array[Top] = x;
    }
}

// Stack operation - pop an item out
int pop() {
    int ele = -1;
    if (Top == -1) {
        printf("\nUnderflow!!");
    } else {
        ele = inp_array[Top];
        Top = Top - 1;
    }
    return ele;
}

// Display the entire stack
void show() {
    if (Top == -1) {
        printf("\nUnderflow!!\n");
    } else {
        printf("\nElements present in the stack: \n");
        for (int i = Top; i >= 0; --i)
            printf("%i\n", inp_array[i]);
    }
}

// Evaluate a operator between two other numbers, all as characters from a string
int eval(int numA, char operator, int numB){

    switch(operator){
        case '+':
            return numA + numB;
        case '-':
            return numA - numB;
        case '*':
            return numA * numB;
        case '/':
            return numA / numB;
        default:
            return 0;
    }
}


short isOperand(char operand){
    if(operand == '+' || operand == '-' || operand == '*' || operand == '/')
        return 1;
    return 0;
}

int calculate(char input[]){
    for(short i=0;i<strlen(input);i++){
        if(!isOperand(input[i])){
            push(input[i]);
        }
        else {
            int a = pop();
            int b = pop();

            int value = eval(a, input[i], b);
            pushRefined(value);
        }
    }



    return inp_array[0];
}
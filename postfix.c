#include "projects/PostfixCalculator.h"

int main(){
    // Test postfix calculator
    printf("POSTFIX CALCULATOR:\n");
//    char equation1[] = "27+12-+";
    char equation1[50];
    scanf("%s", &equation1);
    printf("Result of %s : %d\n\n", equation1, calculate(equation1));

    scanf("%hd", NULL);
}

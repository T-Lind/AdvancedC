#include <stdio.h>
#include "ReadFileLength.h"

int main(){
    FILE *input;


    input = fopen("encryption/data_out.txt", "r");
    int fileLen = getFileLength(input);

    for (int i = 0; i < fileLen; i++) {
        int val = getw(input);
        printf("%d ", val);
    }

    fclose(input);

    scanf("%hd", NULL);
}
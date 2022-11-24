#include <stdio.h>

int getFileLength(FILE *file){
    // Read data
    char c = 0;

    int fileLen = 0;
    while (c != EOF) {
        c = getc(file);
        fileLen++;
    }

    return fileLen;
}
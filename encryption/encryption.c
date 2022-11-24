#include <stdio.h>
#include "ReadFileLength.h"
#include <string.h>

int encode(double rate, short index) {
    double value = 0.5;
    for (int i = 0; i < index; i++)
        value = rate * value * (1 - value);
    return 100000 * value;
}

int main() {
    char data[] = "owo!";

    int fileLen = strlen(data);

    printf("Read data: ");
    char buffer[fileLen];
    for (int i = 0; i < fileLen; i++) {
        buffer[i] = data[i];
        printf("%c", buffer[i]);
    }

    printf("\n\n");

    // Encryption phase
    printf("Encrypted data: ");
    int encryptBuffer[fileLen];
    for (int i = 0; i < fileLen; i++) {
        short character = buffer[i];
        double rate = 3 + (double) character / 255;
        int value = encode(rate, 10);
        encryptBuffer[i] = value;
        printf("%d ", value);
    }

    printf("\n\n");

    char decryptedData[fileLen];
    for (int i = 0; i < fileLen; i++) {
        int num = encryptBuffer[i];

        double rate = 0;
        for (double rateGuess = 3; rateGuess <= 4; rateGuess += (1 / 255.0)) {
            int attempt = encode(rateGuess, 10);
            if (attempt == num) {
                rate = rateGuess;
            }
        }

        if (rate != 0)
            decryptedData[i] = 255.0 * (rate - 3);
        else
            printf(" ERROR ");
    }

    printf("Read data: ");
    for (int i = 0; i < fileLen; i++) {
        printf("%c ", decryptedData[i]);
    }

    scanf("%hd", (short *) (0));
}
#include <stdio.h>
#include <string.h>
#include "KeyGen.h"
#include "limits.h"

double startValue, slope, constant;

long referenceIndex(int i) {
    return startValue * i + constant;
}

unsigned short encode(double rate, long index) {
    double value = startValue;
    for (int i = 0; i < index; i++)
        value = rate * value * (1 - value);
    return USHRT_MAX * cos(2*value);
}

int main() {
    printf("Enter a 19 digit key to encrypt with: ");
    long long KEY;
    scanf("%lld", &KEY);
    printf("\n");

    startValue =  Gen.startValue(KEY);
    slope =  Gen.slope(KEY);
    constant = Gen.constant(KEY);
    printf("Start val: %f\n", startValue);
    printf("Slope: %f\n", slope);
    printf("Constant: %f\n", constant);

    char input[] = "The secret password is XA^40956123!\nDo not share this with anyone, except your homie Joe.";
    int fileLen = strlen(input) + 1;

    char data[fileLen];
    data[0] = ' ';
    for (int i = 1; i < fileLen; i++)
        data[i] = input[i - 1];

    printf("Read data: ");
    char buffer[fileLen];
    for (int i = 0; i < fileLen; i++) {
        buffer[i] = data[i];
        printf("%c", buffer[i]);
    }

    printf("\n\n");

    // Encryption phase
    printf("Encrypted data: ");
    unsigned short encryptBuffer[fileLen];
    for (int i = 0; i < fileLen; i++) {
        short character = buffer[i];
        double rate = 3 + (double) character / 255;
        unsigned short value = encode(rate, referenceIndex(i));
        encryptBuffer[i] = value;
        printf("%d ", value);
    }


    char decryptedData[fileLen];
    for (int i = 0; i < fileLen; i++) {
        unsigned short num = encryptBuffer[i];

        double rate = 0;
        for (double rateGuess = 3; rateGuess <= 4; rateGuess += (1 / 255.0)) {
            int attempt = encode(rateGuess, referenceIndex(i));
            if (attempt == num) {
                rate = rateGuess;
                break;
            }
        }
        int decryptedVal = 255.0 * (rate - 3) + 1;
        decryptedData[i] = decryptedVal;
    }

    printf("\n\n");

    printf("Decrypted data: ");
    for (int i = 1; i < fileLen; i++) {
        printf("\b%c ", decryptedData[i]);
    }

    scanf("%hd", (short *) (0));
}
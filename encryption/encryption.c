#include <stdio.h>
#include <string.h>
#include <math.h>


long referenceIndex(int i) {
    return 3.85 * i + 3 * log(i) + 13;
}

int encode(double rate, long index, double startValue) {
    double value = startValue;
    for (int i = 0; i < index; i++)
        value = rate * value * (1 - value);
    return 100000 * value;
}

int main() {
    double startValue = 1 - sin(sqrt(sqrt(M_E)));


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
    int encryptBuffer[fileLen];
    for (int i = 0; i < fileLen; i++) {
        short character = buffer[i];
        double rate = 3 + (double) character / 255;
        int value = encode(rate, referenceIndex(i), startValue);
        encryptBuffer[i] = value;
//        printf("%f ", rate);
        printf("%d ", value);
    }


    char decryptedData[fileLen];
    for (int i = 0; i < fileLen; i++) {
        int num = encryptBuffer[i];

        double rate = 0;
        for (double rateGuess = 3; rateGuess <= 4; rateGuess += (1 / 255.0)) {
            int attempt = encode(rateGuess, referenceIndex(i), startValue);
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
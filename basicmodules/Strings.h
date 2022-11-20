#include <stdio.h>
#include <string.h>

void strings(){
    printf("STRINGS:\n");

    char str[] = "Hello world!\0 owo"; // The " owo" text is not printed, \0 is a terminating character
    printf("String: %s\n", str);

    // Strings are mutable but cannot be expanded past the size of the static array
    str[12] = '\b';
    str[13] = ' ';
    printf("Modified string: %s\n", str);

    // Explicitly define a string, there's really no reason why you'd do this...
    char str2[] = {'H', 'e', 'y', ',', ' ', 't', 'h', 'e', 'r', 'e', '!', '\0'}; // Notice the terminating \0 on the end!
                                                                                 // implicitly added to normal strings
    printf("Explicitly declared string: %s\n", str2);

    char stringCopy[strlen(str2)];
    strcpy(stringCopy, str2);

    printf("Copied string: %s\n", stringCopy);

    // strcmp - returns 0 = true, > 0 = left string has greater ASCII value, < 0 = right string has greater ASCII value
    printf("Past two strings are the same: %d\n\n", strcmp(stringCopy, str2));
}
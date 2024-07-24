#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fptr = fopen("enc.txt", "wb");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    int seed = 1;
    char* str = "hello wor\"ld!";
    char* encrypted = malloc(strlen(str) + 1); // +1 for the null terminator

    if (encrypted == NULL) {
        perror("Error allocating memory");
        fclose(fptr);
        return 1;
    }

    for (int i = 0; i < strlen(str); i++) {
        encrypted[i] = str[i] + seed;
    }
    encrypted[strlen(str)] = '\0'; // Null terminate the encrypted string

    printf("%s\n", encrypted);
    fprintf(fptr, "%s", encrypted);
    fclose(fptr);

    free(encrypted);
    return 0;
}

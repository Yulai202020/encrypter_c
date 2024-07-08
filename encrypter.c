#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fptr = fopen("enc.txt", "wb");
    int seed = 1;
    char* str = "hello wor\"ld!";
    char* encrypted = malloc(strlen(str));

    for (int i = 0; i < strlen(str); i++) {
        encrypted[i] = str[i] + seed;
    }
    printf(encrypted);
    fprintf(fptr, encrypted);
    fclose(fptr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* available = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !?,.\"/\\#";

int main() {
    FILE *fptr = fopen("enc.txt", "rb");
    int fsize = 0;
    fseek(fptr, 0, SEEK_END);
    fsize = ftell(fptr);
    rewind(fptr);

    char* fcontent = (char*) malloc(sizeof(char) * fsize);
    fread(fcontent, 1, fsize, fptr);

    int count = 0;
    int* can_be = (int*) malloc(255);
    memset(can_be, -1, 255);

    bool idk = false;

    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < strlen(fcontent); j++) {
            if (strchr(available, fcontent[j] - i) == NULL) {
                idk = false;
                break;
            } else {
                idk = true;
            }
        }

        if (idk) {
            can_be[count] = i;
            count++;
            idk = false;
        }
    }

    count = 0;
    while (can_be[count] != -1) {
        for (int i = 0; i < strlen(fcontent); i++) {
            printf("%c", fcontent[i]-can_be[count]);
        }
        printf("\n");
        count++;
    }

    fclose(fptr);
    free(fcontent);
    free(can_be);
}
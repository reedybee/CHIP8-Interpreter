#include <stdio.h>
#include <stdlib.h>

enum { CHAR };

int main(int argc, char* argv[]) {

    FILE* file = fopen("src/pong.rom", "rb");

    if (file == NULL) {
        printf("FAiled to open file\n");
    }

    fseek(file, 0L, SEEK_END);    
    int length = ftell(file);
    rewind(file);

    char* buffer = malloc(247);

    fread(buffer, length, 1, file);

    /*
    // for (int i = 0; i < length; i++) {
    //     if (i % 1 == 0) {
    //         printf(" ");
    //     }
    //     if (i % 16 == 0) {
    //         printf("\n");
    //     }
    //     printf("%02X", (unsigned int)(buffer[i] & 0xFF));
    // }
    */

   

    fclose(file);
    free(buffer);
    printf("\n");
    return 0;   
}
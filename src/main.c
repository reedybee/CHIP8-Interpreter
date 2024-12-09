#include <stdio.h>
#include <stdlib.h>

#include "chip8/interpreter.h"

int main(int argc, char* argv[]) {

    FILE* file = fopen("src/pong.rom", "rb");

    if (file == NULL) {
        printf("Failed to open file\n");
    }

    fseek(file, 0L, SEEK_END);    
    uint32 length = ftell(file);
    rewind(file);

    char* buffer = malloc(length + 1);

    fread(buffer, length, 1, file);

    Interpreter interpreter;

    CreateInterpreter(&interpreter);

    LoadProgramIntoInterpreter(&interpreter, buffer, length, NORMAL_PROGRAM_START);

    RunProgramFromInterpreter(&interpreter);

    DestroyIntepreter(&interpreter);

    fclose(file);
    free(buffer);
    printf("\n");
    return 0;   
}
#include <stdio.h>
#include <stdlib.h>

#include "util/binaryReader.h"

#include "chip8/intepreter.h"

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

    struct BinaryReader binaryReader;
    CreateBinaryReader(&binaryReader, buffer, length);

    struct Interpreter interpreter;

    CreateInterpreter(&interpreter);

    LoadProgramIntoInterpreter(&interpreter, buffer, length, NORMAL_PROGRAM_START);

    //InterpreteROM(&interpreter, &binaryReader);    

    DestroyIntepreter(&interpreter);

    fclose(file);
    free(buffer);
    printf("\n");
    return 0;   
}
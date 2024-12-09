#ifndef INTERPRETER
#define INTERPRETER

#include <stdlib.h>

#include "util/binaryReader.h"
#include "util/util.h"
#include "chip8/optcode.h"

#define NORMAL_PROGRAM_START 0x200

struct Interpreter {
    /* 
        0x000 - 0x200 if for the interpreter 
            first 16 bytes are the variables 0x000 - 0x00F 
            next 2 bytes is the current memory address 0x010 - 0x011
        0x100 - 0x1FF is for display, 255 bytes,
    */
    uint8* memory;

    uint8 PC; // program counter 
    uint16 I; // 12bit register, current memory address
};

void CreateInterpreter(struct Interpreter* interpreter);

void RunProgramFromInterpreter(struct Interpreter* interpreter, struct BinaryReader* binaryReader);

void LoadProgramIntoInterpreter(struct Interpreter* interpreter, char* program, uint32 program_length, uint16 memory_offset);

void WriteMemoryAddress(struct Interpreter* interpreter, uint8 memory);

uint8 ReadMemoryAddress(struct Interpreter* interpreter);

void WriteMemoryPointer(struct Interpreter *interpreter, uint16 pointer);

uint16 ReadMemoryPointer(struct Interpreter* interpreter);


void WriteVariable(struct Interpreter* interpreter, uint8 variable, uint8 value);

uint8 ReadVariable(struct Interpreter* interpreter, uint8 variable);

void DrawSprite(uint8 x, uint8 y, uint8 height);

void DestroyIntepreter(struct Interpreter* interpreter);

#endif
#ifndef INTERPRETER
#define INTERPRETER

#include <stdlib.h>

#include "util/binaryReader.h"
#include "chip8/optcode.h"

struct Interpreter {
    // 0xEA0 - 0xEFF is for call stack and internals
    // 0xF00 - 0xFFF is for display
    unsigned char* memory;

    unsigned char PC; // program counter 
    unsigned short I; // 12bit register

    unsigned char V0; // register 0char V0; // register 0
    unsigned char V1; // register 1char V1; // register 1
    unsigned char V2; // register 2char V2; // register 2
    unsigned char V3; // register 3char V3; // register 3
    unsigned char V4; // register 4char V4; // register 4
    unsigned char V5; // register 5char V5; // register 5
    unsigned char V6; // register 6char V6; // register 6
    unsigned char V7; // register 7char V7; // register 7
    unsigned char V8; // register 8char V8; // register 8
    unsigned char V9; // register 9char V9; // register 9
    unsigned char VA; // register Achar VA; // register A
    unsigned char VB; // register Bchar VB; // register B
    unsigned char VC; // register Cchar VC; // register C
    unsigned char VD; // register Dchar VD; // register D
    unsigned char VE; // register Echar VE; // register E
    unsigned char VF; // register Fchar VF; // register F

    unsigned char* variable_addresses[16];
};

void CreateInterpreter(struct Interpreter* interpreter);

void InterpreteROM(struct Interpreter* interpreter, struct BinaryReader* binaryReader);

void SetVariable(struct Interpreter* interpreter, char variable, char value);

char ReadVariable(struct Interpreter* interpreter, char variable);

void SetMemoryPointer(struct Interpreter *interpreter, short pointer);

void DrawSprite(char x, char y, char height);

void DestroyIntepreter(struct Interpreter* interpreter);

#endif
#ifndef INTERPRETER
#define INTERPRETER

#include <stdlib.h>

#include "util/binaryReader.h"
#include "util/util.h"
#include "chip8/optcode.h"

struct Interpreter {
    // 0x100 - 0x1FF is for display, 255 bytes,
    uint8* memory;

    uint8 PC; // program counter 
    uint16 I; // 12bit register

    uint8 V0; // register 0char V0; // register 0
    uint8 V1; // register 1char V1; // register 1
    uint8 V2; // register 2char V2; // register 2
    uint8 V3; // register 3char V3; // register 3
    uint8 V4; // register 4char V4; // register 4
    uint8 V5; // register 5char V5; // register 5
    uint8 V6; // register 6char V6; // register 6
    uint8 V7; // register 7char V7; // register 7
    uint8 V8; // register 8char V8; // register 8
    uint8 V9; // register 9char V9; // register 9
    uint8 VA; // register Achar VA; // register A
    uint8 VB; // register Bchar VB; // register B
    uint8 VC; // register Cchar VC; // register C
    uint8 VD; // register Dchar VD; // register D
    uint8 VE; // register Echar VE; // register E
    uint8 VF; // register Fchar VF; // register F

    uint8* variable_addresses[16];
};

void CreateInterpreter(struct Interpreter* interpreter);

void InterpreteROM(struct Interpreter* interpreter, struct BinaryReader* binaryReader);

void SetVariable(struct Interpreter* interpreter, uint8 variable, uint8 value);

uint8 ReadVariable(struct Interpreter* interpreter, uint8 variable);

void SetMemoryPointer(struct Interpreter *interpreter, uint16 pointer);

void DrawSprite(uint8 x, uint8 y, uint8 height);

void DestroyIntepreter(struct Interpreter* interpreter);

#endif
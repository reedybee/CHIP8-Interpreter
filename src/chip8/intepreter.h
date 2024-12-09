#ifndef INTERPRETER
#define INTERPRETER

#include <stdlib.h>

#include "util/util.h"

#define NORMAL_PROGRAM_START 0x200

struct Interpreter {
    /* 
        0x000 - 0x200 if for the interpreter 
    */
    uint8* memory;
    uint8* visual_memory;
    uint8* V;
    uint16 PC; // program counter 
    uint16 I; // 12bit register, current memory address
    uint32 program_length;


} typedef Interpreter;

void CreateInterpreter(Interpreter* interpreter);

void RunProgramFromInterpreter(Interpreter* interpreter);

void LoadProgramIntoInterpreter(Interpreter* interpreter, char* program, uint32 program_length, uint16 memory_offset);

void WriteMemoryAddress(Interpreter* interpreter, uint8 memory);

uint8 ReadMemoryAddress(Interpreter* interpreter);

uint8 ReadSpecifiedMemoryAddress(Interpreter* interpreter, uint16 memory_address); 

void WriteMemoryPointer(Interpreter *interpreter, uint16 pointer);

uint16 ReadMemoryPointer(Interpreter* interpreter);

void WriteVariable(Interpreter* interpreter, uint8 variable, uint8 value);

uint8 ReadVariable(Interpreter* interpreter, uint8 variable);

void AdvanceProgramCounter(Interpreter* interpreter);

void DrawSprite(uint8 x, uint8 y, uint8 height);

void ConvertCurrentOptcodeToInstruction(Interpreter* interpreter, uint8* instruction);

void DestroyIntepreter(Interpreter* interpreter);

#endif
#ifndef INTERPRETER
#define INTERPRETER

#include <stdio.h>
#include <stdlib.h>

#include "util/util.h"

#define NORMAL_PROGRAM_START 0x200

typedef struct INTERPRETER_S {
    /* 
        0x000 - 0x200 if for the interpreter 
    */
    uint8* memory;
    uint8* visual_memory;
    uint8* V;
    uint16 PC; // program counter 
    uint16 I; // 12bit register, current memory address
    uint32 program_length;

} Interpreter;

// creates a new interpreter
void CreateInterpreter(Interpreter* interpreter);

// runs the program that has been loading into the interpreters memory
void RunProgramFromInterpreter(Interpreter* interpreter);

// loads a program into the interpreters memory
void LoadProgramIntoInterpreter(Interpreter* interpreter, char* program, uint32 program_length, uint16 memory_offset);

// writes one byte to the current memory address
void WriteMemoryAddress(Interpreter* interpreter, uint8 memory);

// reads one byte from the current memory address
uint8 ReadMemoryAddress(Interpreter* interpreter);

// reads one byte from the specified memory address
uint8 ReadSpecifiedMemoryAddress(Interpreter* interpreter, uint16 memory_address); 

// writes the memory pointer location
void WriteMemoryPointer(Interpreter *interpreter, uint16 pointer);

// reads the memory pointer location
uint16 ReadMemoryPointer(Interpreter* interpreter);

// writes a byte to the specified variable
void WriteVariable(Interpreter* interpreter, uint8 variable, uint8 value);

// reads a byte from the specified variable
uint8 ReadVariable(Interpreter* interpreter, uint8 variable);

// advanceds the program counter by one
void AdvanceProgramCounter(Interpreter* interpreter);

// skips the next optcode
void SkipOptcode(Interpreter* interpreter);

// draws a sprite at x and y with a height
void DrawSprite(uint8 x, uint8 y, uint8 height);

// converts the current optcode to an array of instructions, advances program counter to the next optcode
void ConvertCurrentOptcodeToInstruction(Interpreter* interpreter, uint8* instruction);

// converts the instruction to a memory address
uint16 ConvertInstructionToMemoryAddress(uint8* instruction);

// de-allocates any memory allocated to the interpreter
void DestroyIntepreter(Interpreter* interpreter);

#endif
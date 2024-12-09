#include "chip8/intepreter.h"

void CreateInterpreter(Interpreter* interpreter) {   
    interpreter->memory = malloc(4096);
    interpreter->visual_memory = malloc(64 * 32);
    interpreter->V = malloc(16);
    interpreter->PC = NORMAL_PROGRAM_START;
    interpreter->I = 0;
    interpreter->program_length = 0;
}

void RunProgramFromInterpreter(Interpreter* interpreter) {
    
    WriteMemoryPointer(interpreter, NORMAL_PROGRAM_START);
    // will change
    while (interpreter->PC < interpreter->program_length + NORMAL_PROGRAM_START) {

        uint8 instruction[4];
        ConvertCurrentOptcodeToInstruction(interpreter, instruction);

        if (instruction[0] == 0x1) {

        }
    }
}

void LoadProgramIntoInterpreter(Interpreter* interpreter, char* program, uint32 program_length, uint16 memory_offset) {

    printf("Writing program to interpreter, size: %u bytes\n", program_length);

    for (int i = 0; i < program_length; i++) {
        WriteMemoryPointer(interpreter, i + memory_offset);
        WriteMemoryAddress(interpreter, program[i]);
    }
    WriteMemoryPointer(interpreter, memory_offset);
    interpreter->program_length = program_length;
    printf("Wrote %u bytes to interpreter\n", program_length);
}

void WriteMemoryAddress(Interpreter* interpreter, uint8 memory) {
    interpreter->memory[interpreter->I] = memory;
}

uint8 ReadMemoryAddress(Interpreter* interpreter) {
    return interpreter->memory[interpreter->I];
}

uint8 ReadSpecifiedMemoryAddress(Interpreter* interpreter, uint16 memory_address) {
    return interpreter->memory[memory_address];
}

void WriteMemoryPointer(Interpreter* interpreter, uint16 pointer) {
    interpreter->I = pointer;
}

uint16 ReadMemoryPointer(Interpreter* interpreter) {
    return (interpreter->I);
}

void WriteVariable(Interpreter* interpreter, uint8 variable, uint8 value) {   
    interpreter->V[variable] = value;

    printf("Variable %X set to %02X\n", variable, (int32)interpreter->memory[variable]);
}

uint8 ReadVariable(Interpreter* interpreter, uint8 variable) {
    uint8 value = interpreter->V[variable];

    printf("Variable %X read as %02X\n", variable, value);

    return value;
}

void AdvanceProgramCounter(Interpreter* interpreter) {
    interpreter->PC++;
}

void DrawSprite(uint8 x, uint8 y, uint8 height) {
    //
    printf("Sprite drawn at (%X, %X)\n", x, y);
}

void ConvertCurrentOptcodeToInstruction(Interpreter* interpreter, uint8* instruction) {
    // reads the next two bytes, the optcode
    uint8 high_byte = ReadSpecifiedMemoryAddress(interpreter, interpreter->PC);
    AdvanceProgramCounter(interpreter);
    uint8 low_byte = ReadSpecifiedMemoryAddress(interpreter, interpreter->PC);
    AdvanceProgramCounter(interpreter);
    
    // converts the optcode into 4 uint8's that are the instruction
    instruction[0] = (high_byte >> 4) & 0x0F;
    instruction[1] =  high_byte       & 0x0F;
    instruction[2] = (low_byte  >> 4) & 0x0F;
    instruction[3] =  low_byte        & 0x0F;
}

void DestroyIntepreter(Interpreter* interpreter) {
    free(interpreter->memory);
    free(interpreter->visual_memory);
    free(interpreter->V);
}
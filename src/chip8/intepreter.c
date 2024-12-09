#include "chip8/intepreter.h"

void CreateInterpreter(struct Interpreter* interpreter) {   
    interpreter->memory = malloc(4096);
    interpreter->PC = 0;
    interpreter->I = 0; 
}

void RunProgramFromInterpreter(struct Interpreter* interpreter, struct BinaryReader* binaryReader) {
    while (binaryReader->eob == 0) {
        
        uint8 nibble = ReadNibble(binaryReader);

        if (nibble == -1)
            return;

        if (nibble == 0xA) {
            uint16 memory_pointer = ReadByte(binaryReader);

            WriteMemoryPointer(interpreter, memory_pointer);
        }
        if (nibble == 0xB) {
            uint16 memory_pointer = interpreter->I + ReadVariable(interpreter, 0x0); 

            WriteMemoryPointer(interpreter, memory_pointer);
        }
        if (nibble == 0xC) {
            uint8 variable = ReadNibble(binaryReader);
            uint8 number = ReadByte(binaryReader);

            WriteVariable(interpreter, variable, ((rand() % 255 - 0 + 1) + 1) & number);
        }

        if (nibble == 0x6) {
            uint8 variable = ReadNibble(binaryReader);

            uint8 high_nibble = ReadNibble(binaryReader);
            uint8 low_nibble = ReadNibble(binaryReader);

            uint8 value = (high_nibble << 4) | low_nibble;

            WriteVariable(interpreter, variable, value);
        }
        if (nibble == 0xD) {
            //display
            uint8 x_pos = ReadVariable(interpreter, ReadNibble(binaryReader));
            uint8 y_pos = ReadVariable(interpreter, ReadNibble(binaryReader));

            uint8 height = ReadNibble(binaryReader);

            DrawSprite(x_pos, y_pos, height);
        }
    }
}

void LoadProgramIntoInterpreter(struct Interpreter* interpreter, char* program, uint32 program_length, uint16 memory_offset) {

    printf("Writing program to interpreter, size: %u bytes\n", program_length);

    for (int i = 0; i < program_length; i++) {
        WriteMemoryPointer(interpreter, i + memory_offset);
        WriteMemoryAddress(interpreter, program[i]);
    }
    WriteMemoryPointer(interpreter, memory_offset);
    printf("Wrote %u bytes to interpreter", program_length);
}

void WriteMemoryAddress(struct Interpreter* interpreter, uint8 memory) {
    interpreter->memory[interpreter->I] = memory;

    printf("Memory at pointer wrote to %02X\n", interpreter->memory[interpreter->I]);
}

uint8 ReadMemoryAddress(struct Interpreter* interpreter) {
    return interpreter->memory[interpreter->I];
}

void WriteMemoryPointer(struct Interpreter* interpreter, uint16 pointer) {
    interpreter->I = pointer;

    printf("Memory pointer set to: %X\n", pointer);
}

uint16 ReadMemoryPointer(struct Interpreter* interpreter) {
    return (interpreter->I);
}

void WriteVariable(struct Interpreter* interpreter, uint8 variable, uint8 value) {   
    interpreter->memory[variable] = value;

    printf("Variable %X set to %02X\n", variable, (int32)interpreter->memory[variable]);
}

uint8 ReadVariable(struct Interpreter* interpreter, uint8 variable) {
    uint8 value = interpreter->memory[variable];

    printf("Variable %X read as %02X\n", variable, value);

    return value;
}

void DrawSprite(uint8 x, uint8 y, uint8 height) {
    //
    printf("Sprite drawn at (%X, %X)\n", x, y);
}

void DestroyIntepreter(struct Interpreter* interpreter) {
    free(interpreter->memory);
}
#include "chip8/intepreter.h"

void CreateInterpreter(struct Interpreter* interpreter) {   
    interpreter->memory = malloc(4096);
    interpreter->PC = 0;
    interpreter->I = 0; 
    interpreter->V0 = 0;    interpreter->variable_addresses[0x0] = &interpreter->V0;
    interpreter->V1 = 0;    interpreter->variable_addresses[0x1] = &interpreter->V1;
    interpreter->V2 = 0;    interpreter->variable_addresses[0x2] = &interpreter->V2;
    interpreter->V3 = 0;    interpreter->variable_addresses[0x3] = &interpreter->V3;
    interpreter->V4 = 0;    interpreter->variable_addresses[0x4] = &interpreter->V4;
    interpreter->V5 = 0;    interpreter->variable_addresses[0x5] = &interpreter->V5;
    interpreter->V6 = 0;    interpreter->variable_addresses[0x6] = &interpreter->V6;
    interpreter->V7 = 0;    interpreter->variable_addresses[0x7] = &interpreter->V7;
    interpreter->V8 = 0;    interpreter->variable_addresses[0x8] = &interpreter->V8;
    interpreter->V9 = 0;    interpreter->variable_addresses[0x9] = &interpreter->V9;
    interpreter->VA = 0;    interpreter->variable_addresses[0xA] = &interpreter->VA;
    interpreter->VB = 0;    interpreter->variable_addresses[0xB] = &interpreter->VB;
    interpreter->VC = 0;    interpreter->variable_addresses[0xC] = &interpreter->VC;
    interpreter->VD = 0;    interpreter->variable_addresses[0xD] = &interpreter->VD;
    interpreter->VE = 0;    interpreter->variable_addresses[0xE] = &interpreter->VE;
    interpreter->VF = 0;    interpreter->variable_addresses[0xF] = &interpreter->VF;
}

void InterpreteROM(struct Interpreter* interpreter, struct BinaryReader* binaryReader) {
    while (binaryReader->eob == 0) {
        
        unsigned char nibble = ReadNibble(binaryReader);

        if (nibble == -1)
            return;

        if (nibble == 0xA) {
            short memory_pointer = ReadByte(binaryReader);

            SetMemoryPointer(interpreter, memory_pointer);
        }
        if (nibble == 0xB) {
            short memory_pointer = interpreter->I + ReadVariable(interpreter, 0x0); 

            SetMemoryPointer(interpreter, memory_pointer);
        }
        if (nibble == 0xC) {
            char variable = ReadNibble(binaryReader);
            char number = ReadByte(binaryReader);

            SetVariable(interpreter, variable, ((rand() % 255 - 0 + 1) + 1) & number);
        }

        if (nibble == 0x6) {
            unsigned char variable = ReadNibble(binaryReader);

            unsigned char high_nibble = ReadNibble(binaryReader);
            unsigned char low_nibble = ReadNibble(binaryReader);

            unsigned char value = (high_nibble << 4) | low_nibble;

            SetVariable(interpreter, variable, value);
        }
        if (nibble == 0xD) {
            //display
            unsigned char x_pos = ReadVariable(interpreter, ReadNibble(binaryReader));
            unsigned char y_pos = ReadVariable(interpreter, ReadNibble(binaryReader));

            unsigned char height = ReadNibble(binaryReader);

            DrawSprite(x_pos, y_pos, height);
        }
    }
}

void SetVariable(struct Interpreter* interpreter, uint8 variable, uint8 value) {   
    *interpreter->variable_addresses[variable] = value;

    printf("Variable %X set to %02X\n", variable, (int)*interpreter->variable_addresses[variable]);
}

uint8 ReadVariable(struct Interpreter* interpreter, uint8 variable) {
    char value = *interpreter->variable_addresses[variable];

    printf("Variable %X read as %02X\n", variable, value);

    return value;
}

void SetMemoryPointer(struct Interpreter *interpreter, uint16 pointer) {
    interpreter->I = pointer;

    printf("Memory pointer set to: %X\n", pointer);
}

void DrawSprite(uint8 x, uint8 y, uint8 height) {
    //
    printf("Sprite drawn at (%X, %X)\n", x, y);
}

void DestroyIntepreter(struct Interpreter* interpreter) {
    free(interpreter->memory);
}
#include "chip8/intepreter.h"

void CreateInterpreter(struct Interpreter* interpreter) {   
    interpreter->memory = malloc(512);
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

void InterperateROM(struct Interpreter* interpreter, struct BinaryReader* binaryReader) {
    while (binaryReader->eob == 0) {
        
        unsigned char nibble = ReadNibble(binaryReader);

        if (nibble == -1)
            return;

        if (nibble == 0x6) {
            unsigned char variable = ReadNibble(binaryReader);

            unsigned char high_nibble = ReadNibble(binaryReader);
            unsigned char low_nibble = ReadNibble(binaryReader);

            unsigned char value = (high_nibble << 4) | low_nibble;

            SetVariable(interpreter, variable, value);
        }
        if (nibble == 0xA) {
            
        }
    }

    
}

void SetVariable(struct Interpreter* interpreter, char variable, char value) {   
            *interpreter->variable_addresses[variable] = value;

            printf("Variable %X set to %02X\n", variable, (int)*interpreter->variable_addresses[memory_address]);
}

void SetMemoryPointer(struct Interpreter *interpreter, char pointer) {

}
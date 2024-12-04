
#include "chip8/intepreter.h"

void InterperateROM(struct BinaryReader* binaryReader) {
    while (binaryReader->eob == 0) {
        char nibble = ReadNibble(binaryReader);
        if (nibble == -1)
            return;

        printf("%X", nibble);
    }
}
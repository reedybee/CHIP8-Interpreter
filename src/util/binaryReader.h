#ifndef BINARY_READER
#define BINARY_READER

#include <stdio.h>

#define LOW_NIBBLE 0
#define HIGH_NIBBLE 1

#include "util/util.h"

struct BinaryReader {
    char* buffer;
    uint32 pointer; // pointer to the current byte
    uint8 eob; // end of buffer; 0 false, 1 true
    uint8 nibble_flag;
    uint32 buffer_size;
};

void CreateBinaryReader(struct BinaryReader* binaryReader, char* file, uint32 buffer_size);

void AdvancePointer(struct BinaryReader* binaryReader, uint32 numberToAdvance);


// reads current nibble and advances pointer
char ReadNibble(struct BinaryReader* binaryReader);

// reads the what_nibble at pointer where what_nibble = 0 is low, 1 is high;
char ReadSpecifiedNibble(struct BinaryReader* binaryReader, uint32 pointer, uint32 what_nibble);

// reads byte
char ReadByte(struct BinaryReader* binaryReader);

// reads current double byte, does not advance pointers
short ReadDoubleByte(struct BinaryReader* binaryReader);

#endif
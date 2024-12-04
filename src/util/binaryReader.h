#ifndef BINARY_READER
#define BINARY_READER

#include <stdio.h>

#define LOW_NIBBLE 0
#define HIGH_NIBBLE 1

struct BinaryReader {
    char* buffer;
    int pointer; // pointer to the current byte
    int eob; // end of buffer; 0 false, 1 true
    int nibble_flag;
    size_t buffer_size;
};

void CreateBinaryReader(struct BinaryReader* binaryReader, char* file, size_t buffer_size);

void AdvancePointer(struct BinaryReader* binaryReader, int numberToAdvance);


// reads current nibble and advances pointer
char ReadNibble(struct BinaryReader* binaryReader);

// reads the what_nibble at pointer where what_nibble = 0 is low, 1 is high;
char ReadSpecifiedNibble(struct BinaryReader* binaryReader, unsigned int pointer, unsigned int what_nibble);

// reads byte
char ReadByte(struct BinaryReader* binaryReader);

// reads current double byte, does not advance pointers
short ReadDoubleByte(struct BinaryReader* binaryReader);

#endif
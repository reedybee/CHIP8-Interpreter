#include <util/binaryReader.h>

void CreateBinaryReader (struct BinaryReader* binaryReader, char* file, size_t file_size) {
    binaryReader->buffer = file;
    binaryReader->pointer = 0;
    binaryReader->eob = 0;
    binaryReader->buffer_size = file_size;
    binaryReader->nibble_flag = 0;
}

void AdvancePointer(struct BinaryReader* binaryReader, int numberToAdvance) {
    binaryReader->pointer += numberToAdvance;
}

char ReadNibble(struct BinaryReader* binaryReader) {
    if (binaryReader->pointer >= binaryReader->buffer_size) {
        printf("\nPointer has reached end of file\n");
        binaryReader->eob = 1;
        return -1;
    }

    char byte = binaryReader->buffer[binaryReader->pointer];
    char nibble;

    if (binaryReader->nibble_flag == 0) {
        nibble = (byte >> 4) & 0xF;
        binaryReader->nibble_flag = 1;
    } else {
        nibble = byte & 0xF;
        binaryReader->nibble_flag = 0; 
        binaryReader->pointer += 1;
    }

    return nibble;
}

char ReadSpecifiedNibble(struct BinaryReader* binaryReader, unsigned int pointer, unsigned int what_nibble) {
    if (pointer >= binaryReader->buffer_size) {
        printf("Cannot read past size of buffer");
        return 0;
    }

    char byte = binaryReader->buffer[pointer];
    char nibble;

    if (what_nibble == LOW_NIBBLE) {
        nibble = (byte >> 4) & 0xF;
        binaryReader->nibble_flag = 1;
    } else if (what_nibble == HIGH_NIBBLE) {
        nibble = byte & 0xF;
        binaryReader->nibble_flag = 0;
    }

    return nibble;
}

short ReadTribble(struct BinaryReader* binaryReader) {
    unsigned char first_nibble = ReadNibble(binaryReader);
    unsigned char second_nibble = ReadNibble(binaryReader);
    unsigned char third_nibble = ReadNibble(binaryReader); 

    short tribble = first_nibble;

    tribble <<= 4;
    tribble |= second_nibble;
    tribble <<= 4;
    tribble |= third_nibble;

    return tribble;
}

char ReadByte(struct BinaryReader* binaryReader) {
    if (binaryReader->pointer >= binaryReader->buffer_size) {
        printf("Pointer has reached end of file");
        binaryReader->eob = 1;
        return -1;
    }

    char high_nibble = ReadNibble(binaryReader);
    char low_nibble = ReadNibble(binaryReader);
    
    char byte = (high_nibble << 4) | low_nibble;

    return byte;
}

short ReadDoubleByte(struct BinaryReader* binaryReader) {

    unsigned char current_byte = ReadByte(binaryReader);
    unsigned char next_byte = ReadByte(binaryReader);

    short double_byte;

    double_byte = current_byte;
    double_byte = (current_byte << 8) | next_byte;

    return double_byte;
}
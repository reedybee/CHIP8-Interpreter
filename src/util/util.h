#ifndef UTIL
#define UTIL

#define uint8  unsigned char
#define uint16 unsigned short
#define uint32 unsigned int
#define uint64 unsigned long

#define int8  char
#define int16 short
#define int32 int
#define int64 long

uint16 ConvertFromUint8ToUint16(uint8 high_byte, uint8 low_byte) {
    return (uint16)((high_byte << 4) << low_byte);
}

#endif
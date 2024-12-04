GCC := gcc
CFLAGS := -Wall -std=c23

MAIN_IN := src/main.c
MAIN_OUT := src/main.exe

SOURCE_FILES := $(wildcard src/*/*.c)
INCLUDE_FILES := -Isrc/

make:
	$(GCC) $(CFLAGS) $(SOURCE_FILES) $(MAIN_IN) -o $(MAIN_OUT) $(INCLUDE_FILES)

run: make
	gdb -q $(MAIN_OUT)
GCC := gcc
CFLAGS := --verbose -Wall

MAIN_IN := src/main.c
MAIN_OUT := src/main.exe

make:
	$(GCC) $(CFLAGS) $(MAIN_IN) -o $(MAIN_OUT)

run: make
	$(MAIN_OUT)
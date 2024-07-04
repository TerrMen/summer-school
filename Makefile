CC=riscv64-linux-gnu-gcc
SOURCES=src/main.c src/clear.c src/get.c src/print.c
FLAGS=-static -o main

all:
	$(CC) $(FLAGS) $(SOURCES)

CC=riscv64-linux-gnu-gcc
SOURCES=src/main.c src/clear.c src/get.c src/print.c src/error_treatment.c
FLAGS=-static -o main -Wall -Wextra

all:
	$(CC) $(FLAGS) $(SOURCES)

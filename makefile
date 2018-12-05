CC = gcc

main.exe: main.c calculations.o
	$(CC) -o main main.c calculations.o

calculations.o: calculations.h calculations.c
	gcc -c calculations.c

clean:
	rm main.exe calculations.o
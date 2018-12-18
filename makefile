CC = gcc

main.exe: main.c calculations.o convertstrings.o
	$(CC) -o main main.c calculations.o convertstrings.o

calculations.o: calculations.h calculations.c
	gcc -c calculations.c

convertstrings.o: convertstrings.h convertstrings.c
	gcc -c convertstrings.c

clean:
	rm main.exe calculations.o convertstrings.o
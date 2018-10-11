CC = gcc

main.exe: main.c SumTest.o
	$(CC) -o main main.c SumTest.o

SumTest.o: SumTest.c SumTest.h
	gcc -c SumTest.c

clean:
	rm main.exe
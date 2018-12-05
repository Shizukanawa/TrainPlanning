CC = gcc

main.exe: main.c SumTest.o
	$(CC) -o main main.c SumTest.o

clean:
	rm main.exe
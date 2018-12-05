CC = gcc

main.exe: main.c SumTest.o
	$(CC) -o main main.c

clean:
	rm main.exe
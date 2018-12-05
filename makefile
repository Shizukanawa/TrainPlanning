CC = gcc

main.exe: main.c
	$(CC) -o main main.c

clean:
	rm main.exe
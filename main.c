#include <stdio.h>
#include <stdlib.h>
const int AMOUNT_OF_TRAINS = 10;
enum Status {Off = 1, OnRoute, Down};

typedef struct Train
{
    double Velocity;
    int X;
    int Y;
    int Status;
} Train;

int main(void)
{
    int i = 0;
    printf("I like trains");
    i = Sum(5, 2);
    printf("%d\n", i);
    scanf("%d");
    return EXIT_SUCCESS;
}


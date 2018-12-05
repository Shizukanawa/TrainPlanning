#include <stdio.h>
#include <stdlib.h>
const int AMOUNT_OF_TRAINS = 10;
enum Status
{
    Off = 1,
    Enroute,
    Down
};

typedef struct Train
{
    double Velocity;
    int Status;
} Train;

Train changeStatus(Train train, int status);

int main(void)
{
    Train IC4[AMOUNT_OF_TRAINS];
    int i;
    for(i = 0; i < AMOUNT_OF_TRAINS; ++i)
    {
        IC4[i].Status = Off;
        printf("IC4: %d, Status: %d\n", i, IC4[i].Status);
    }
    changeStatus(IC4[0], Down);
    printf("IC4: %d, Status: %d\n", 0, IC4[0].Status);
    return EXIT_SUCCESS;
}

Train changeStatus(Train train, int status)
{
    train.Status = status;
    return train;
}

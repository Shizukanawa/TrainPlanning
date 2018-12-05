#include <stdio.h>
#include <stdlib.h>

const int AMOUNT_OF_STATIONS = 27;
const int AMOUNT_OF_TRAINS = 10;

enum Station
{
    Aalborg = 0,
    Skalborg,
    Svenstrup,
    Støvring,
    Skørping,
    Arden,
    Hobro,
    Randers,
    Langå,
    Hadsten,
    Århus,
    Skanderborg,
    Horsens,
    Vejle,
    Fredericia,
    Middelfart,
    Odense,
    Langeskov,
    Nyborg,
    Korsør,
    Slagelse,
    Sorø,
    Ringsted,
    Roskilde,
    Høje_Taastrup,
    Valby,
    København
};

enum Status
{
    Off,
    Enroute,
    Down
};

typedef struct Train
{
    double Velocity;
    int Status;
} Train;

Train moveTrain(Train *train, int station);
Train changeStatus(Train train, int status);

int main(void)
{
    Train IC4[AMOUNT_OF_TRAINS];
    int i;

    for (i = 0; i < AMOUNT_OF_TRAINS; ++i)
    {
        IC4[i].Status = Off;
        printf("IC4: %d, Status: %d\n", i, IC4[i].Status);
    }

    IC4[0] = changeStatus(IC4[0], Down);
    printf("IC4: %d, Status: %d\n", 0, IC4[0].Status);
    return EXIT_SUCCESS;
}

Train changeStatus(Train train, int status)
{
    train.Status = status;
    return train;
}

Train moveTrain(Train *train, int station)
{
    int i, j;
    for(i = 0; i < AMOUNT_OF_TRAINS; i++){
        if (train[i].Status !=  Off || Down){

        }
    }
}

double calculateDistance(double )
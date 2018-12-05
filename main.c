/* Point1: 57.043243, 9.917183 */
/* Point2: 57.008360, 9.898382 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    Koebenhavn
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
    int Stations;
} Train;

Train changeStatus(Train train, int status);
Train moveTrain(Train *train, int station);
double calculateDistance(double lat1, double long1, double lat2, double long2);
double calculateRad(double degrees);

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
    printf("%d to %lf", 1, calculateRad(1));
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

double calculateDistance(double lat1, double long1, double lat2, double long2)
{
    double R = 6371000, Phi, Lambda; /* Formular from https://www.movable-type.co.uk/scripts/latlong.html */
    
}

double calculateRad(double degrees)
{
    return degrees * M_PI / 180;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculations.h"

const int AMOUNT_OF_STATIONS = 27;
const int AMOUNT_OF_TRAINS = 10;

enum Station
{
    Aalborg = 0,
    Skalborg,
    Svenstrup,
    Stoevring,
    Skoerping,
    Arden,
    Hobro,
    Randers,
    Langaa,
    Hadsten,
    Aarhus,
    Skanderborg,
    Horsens,
    Vejle,
    Fredericia,
    Middelfart,
    Odense,
    Langeskov,
    Nyborg,
    Korsoer,
    Slagelse,
    Soroe,
    Ringsted,
    Roskilde,
    Hoeje_Taastrup,
    Valby,
    Koebenhavn
};

enum Status
{
    Off,
    Onstation,
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
char *nameOfStation(int station);

/* Point1: 57.043243, 9.917183 */
/* Point2: 57.008360, 9.898382 */

int main(void)
{
    Train IC4[AMOUNT_OF_TRAINS];
    double distances[26] = {4.3, 4.8, 9.7, 7.5, 15.5, 31.3, 13.4, 22.5,
                            32.6, 22.8, 31.4, 25.7, 10.2, 50.1, 14.0, 14.7,
                            23.3, 15.4, 14.6, 14.4, 32.6, 11.8, 15.6, 3.9};
    int i;

    for (i = 0; i < AMOUNT_OF_TRAINS; ++i)
    {
        IC4[i].Status = Off;
        printf("IC4: %d, Status: %d\n", i, IC4[i].Status);
    }

    IC4[0] = changeStatus(IC4[0], Down);
    printf("IC4: %d, Status: %d\n", 0, IC4[0].Status);
    printf("%s", nameOfStation(0));
    return EXIT_SUCCESS;
}

Train changeStatus(Train train, int status)
{
    train.Status = status;
    return train;
}

char *nameOfStation(int station)
{
    static char *station_array[AMOUNT_OF_STATIONS] = {"Aalborg",
                                                      "Skalborg",
                                                      "Svenstrup",
                                                      "Stoevring",
                                                      "Skoerping",
                                                      "Arden",
                                                      "Hobro",
                                                      "Randers",
                                                      "Langaa",
                                                      "Hadsten",
                                                      "Aarhus",
                                                      "Skanderborg",
                                                      "Horsens",
                                                      "Vejle",
                                                      "Fredericia",
                                                      "Middelfart",
                                                      "Odense",
                                                      "Langeskov",
                                                      "Nyborg",
                                                      "Korsoer",
                                                      "Slagelse",
                                                      "Soroe",
                                                      "Ringsted",
                                                      "Roskilde",
                                                      "Hoeje_Taastrup",
                                                      "Valby",
                                                      "Koebenhavn"};
    return station_array[station];
}

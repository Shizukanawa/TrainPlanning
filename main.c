#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculations.h"
#define a "station"
#define b "tog nr"
#define c "tid"

const int AMOUNT_OF_STATIONS = 27;
const int AMOUNT_OF_TRAINS = 10;
const int MAX_LGT = 20;

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

typedef struct Station
{
    char Station;
    double latitude;
    double longitude;
} Station;

typedef struct Train
{
    double Velocity;
    int Status;
    int Stations;
} Train;

Train changeStatus(Train train, int status);
char *nameOfStation();
void printTop();
void printTable();

/* Point1: 57.043243, 9.917183 */
/* Point2: 57.008360, 9.898382 */

int main(void)
{
    Train IC4[AMOUNT_OF_TRAINS];
    double distances[26] = {4.3, 4.8, 9.7, 7.5, 15.5, 31.3, 13.4, 22.5,
                            32.6, 22.8, 31.4, 25.7, 10.2, 50.1, 14.0, 14.7,
                            23.3, 15.4, 14.6, 14.4, 32.6, 11.8, 15.6, 3.9};
    int i;

    for(i = 0; i < AMOUNT_OF_TRAINS; ++i)
    {
        IC4[i].Status = Off;
        printf("IC4: %d, Status: %d\n", i, IC4[i].Status);
    }

    IC4[0] = changeStatus(IC4[0], Down);
    printf("IC4: %d, Status: %d\n", 0, IC4[0].Status);

    printf("Printing table\n");
    printTable();
    return EXIT_SUCCESS;
}

Train changeStatus(Train train, int status)
{
    train.Status = status;
    return train;
}

char *nameOfStation(int station)
{
    static char *station_array[] = {"Aalborg", "Skalborg", "Svenstrup", "Stoevring", "Skoerping", "Arden", "Hobro",
                                    "Randers", "Langaa", "Hadsten", "Aarhus", "Skanderborg", "Horsens", "Vejle",
                                    "Fredericia", "Middelfart", "Odense", "Langeskov", "Nyborg", "Korsoer", "Slagelse",
                                    "Soroe", "Ringsted", "Roskilde", "Hoeje Taastrup", "Valby", "Koebenhavn"};
    return station_array[station];
}

void printTop(char *stations)
{
<<<<<<< HEAD
=======
    printf("Tog nr: %-5d %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s\n", 5,
    stations[0], stations[1], stations[2], stations[3],
    stations[4], stations[5], stations[6], stations[7],
    stations[8], stations[9], stations[10], stations[11],
    stations[12], stations[13], stations[14], stations[15],
    stations[16], stations[17], stations[18], stations[19],
    stations[20], stations[21], stations[22], stations[23],
    stations[24], stations[25], stations[26]);
>>>>>>> 38bde283c0e19e9e48500c882f0b465f7bb29965
}

void printTable()
{
<<<<<<< HEAD
    printf("Tog nr: %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s\n", a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
=======
    printf("Tog nr: %-5d %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s\n", a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
>>>>>>> 38bde283c0e19e9e48500c882f0b465f7bb29965
}

void scanstations()
{
    int i;
    FILE *fp;
    fp = fopen("stationer.txt", "r");
    if (fp == NULL)
    {
        printf("Kunne ikke finde filen.\n");
        return (EXIT_FAILURE);
    }
    /*sætter fil pointeren tilbage til starten af filen*/
    rewind(fp);
    for (i = 0; i <= AMOUNT_OF_STATIONS; i++)
    {
        fscanf(fp, " %s | %lf | &lf |",
               Stations[i].Station,
               Stations[i].latitude,
               Stations[i].longitude);
    }
}
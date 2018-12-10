#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculations.h"
<<<<<<< HEAD
#define a "station"
=======
#define a "05:50"
>>>>>>> b554f8656f0f3f0259669aaeea8c14c3ffafaaf2
#define b "tog nr"
#define c "tid"
#define MAX_LGT 20

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

typedef struct Stations
{
    char StationName[MAX_LGT];
    double Latitude;
    double Longitude;
} Stations;

typedef struct Train
{
    double Velocity;
    int Status;
    int Stations;
} Train;

Train changeStatus(Train train, int status);
char *nameOfStation(int station);
void getStations(Stations *s);
void printTop(Stations *s);
void printTable();
<<<<<<< HEAD
int *calculateTime(double distances, int speed);
=======
>>>>>>> b554f8656f0f3f0259669aaeea8c14c3ffafaaf2

/* Point1: 57.043243, 9.917183 */
/* Point2: 57.008360, 9.898382 */

int main(void)
{
    Train IC4[AMOUNT_OF_TRAINS];
    int i, j = 0;
    Stations s[AMOUNT_OF_STATIONS];
    getStations(s);
    for (i = 0; i < AMOUNT_OF_TRAINS; ++i)
    {
        IC4[i].Status = Off;
        printf("IC4: %d, Status: %d\n", i, IC4[i].Status);
    }
    IC4[0] = changeStatus(IC4[0], Down);
    printf("IC4: %d, Status: %d\n", 0, IC4[0].Status);
<<<<<<< HEAD
    j = 0;
    printf("Name: %s, Lat: %lf, Lon: %lf\n", s[j].StationName, s[j].Latitude, s[j].Longitude);
    /*printf("Printing table\n");
    printTable();*/
=======
    printf("Name: %s, Lat: %lf, Lon: %lf\n", s[j].StationName, s[j].Latitude, s[j].Longitude);
    printf("Printing table\n");
    printTop(s);
    printTable();
>>>>>>> b554f8656f0f3f0259669aaeea8c14c3ffafaaf2
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

void printTop(Stations *s)
{
    int i;
<<<<<<< HEAD
    printf("Tog nr: %-5s", s[0].StationName);
    for (i = 0; i < AMOUNT_OF_STATIONS; i++)
    {
        printf(" %-5s", s[i].StationName);
    }
=======
    printf("Station:       %-6.5s", s[0].StationName);
    for (i = 1; i < AMOUNT_OF_STATIONS; i++)
    {
        printf(" %-6.5s", s[i].StationName);
    }
    printf("\n");
>>>>>>> b554f8656f0f3f0259669aaeea8c14c3ffafaaf2
}

void printTable()
{
<<<<<<< HEAD
    printf("Tog nr: %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s %-5s\n", a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
=======
    printf("Tog nr: %-6d %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s\n", 1, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
>>>>>>> b554f8656f0f3f0259669aaeea8c14c3ffafaaf2
}

void getStations(Stations *s)
{
    int i;
    FILE *fp;
    fp = fopen("Stationer.txt", "r");
    if (fp == NULL)
        printf("Stationer.txt not found\n");
    else
    {
        for (i = 0; i <= AMOUNT_OF_STATIONS; i++)
        {
            fscanf(fp, "%s %lf %lf\n",
                   s[i].StationName,
                   &s[i].Latitude,
                   &s[i].Longitude);
        }
        fclose(fp);
    }
<<<<<<< HEAD
}

int *calculateTime(double distances, int speed) {
    static int time[3];
    int hours, rest;

    hours = ((int )distances / speed) * 60;

    time[1] = hours / 3600;
    rest = hours % 3600;
    time[2] = rest / 60;
    rest = rest % 60;
    time[3] = rest;

    return time;
=======
>>>>>>> b554f8656f0f3f0259669aaeea8c14c3ffafaaf2
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculations.h"
#define a "05:50"
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
int *calculateTime(double distances, int speed);
/* Point1: 57.043243, 9.917183 */
/* Point2: 57.008360, 9.898382 */

int main(void)
{
    Train IC4[AMOUNT_OF_TRAINS];
    int i, j = 0, *speed;
    Stations s[AMOUNT_OF_STATIONS];
    getStations(s);
    for (i = 0; i < AMOUNT_OF_TRAINS; ++i)
    {
        IC4[i].Status = Off;
        printf("IC4: %d, Status: %d\n", i, IC4[i].Status);
    }
    printTop(s);
    IC4[0] = changeStatus(IC4[0], Down);
    speed = calculateTime(1000, 180);
    printf("IC4: %d, Status: %d\n", 0, IC4[0].Status);
    printf("Name: %s, Lat: %lf, Lon: %lf\n", s[j].StationName, s[j].Latitude, s[j].Longitude);
    printf("Printing table\n");
    printTop(s);
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

void printTop(Stations *s)
{
    int i;
    printf("Station:       %-6.5s", s[0].StationName);
    for (i = 1; i < AMOUNT_OF_STATIONS; i++)
        printf(" %-6.5s", s[i].StationName);
    printf("\n");
}

void printTable()
{
    printf("Tog nr: %-6d %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s\n", 1, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
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
}

int *calculateTime(double distances, int speed) {
    static int time[3];
    double maxTime;
    int hours = 0, rest = 0;

    maxTime = (distances / speed) * 3600;

    time[0] = (int)maxTime / 3600;
    rest = (int)maxTime % 3600;
    time[1] = rest / 60;
    rest = rest % 60;
    time[2] = rest;

    return time;
}
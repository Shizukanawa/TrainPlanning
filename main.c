#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calculations.h"
#define a "05:50"
#define b "tog nr"
#define c "tid"
#define MAX_LGT 20
#define infinite 9999

const int AMOUNT_OF_STATIONS = 27;
const int AMOUNT_OF_TRAINS = 10;

typedef enum Station
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
} Station;

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
    int Connections[3];
} Stations;

typedef struct Train
{
    double Velocity;
    int Status;
    int Stations;
} Train;

char *nameOfStation(int station);
void getStations(Stations *s);
void printTop(Stations *s);
void printTable();
int *calculateTime(double distances, int speed);
void findRoute(Stations *s, int start, int end);

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
    IC4[0].Status = Enroute;
    speed = calculateTime(1000, 180);
    printf("IC4: %d, Status: %d\n", 0, IC4[0].Status);
    printf("Name: %s, Lat: %lf, Lon: %lf\n", s[j].StationName, s[j].Latitude, s[j].Longitude);
    printf("Printing table\n");
    printTop(s);
    printTable();
    findRoute(s, Aalborg, Koebenhavn);
    return EXIT_SUCCESS;
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
    int i, j;
    char connections[10], *token, delim[2] = ",";
    FILE *fp;
    fp = fopen("Stationer.txt", "r");
    if (fp == NULL)
        printf("Stationer.txt not found\n");
    else
    {
        for (i = 0; i < AMOUNT_OF_STATIONS; i++)
        {
            fscanf(fp, "%s %lf %lf %[0-9,]\n",
                   s[i].StationName,
                   &s[i].Latitude,
                   &s[i].Longitude,
                   connections);
            token = strtok(connections, delim);
            j = 0;
            while(token != NULL)
            {
                s[i].Connections[j] = atoi(token);
                token = strtok(NULL, delim);
                ++j;
            }
        }
        fclose(fp);
    }
}

int *calculateTime(double distances, int speed)
{
    static int time[3];
    double maxTime;
    int hours = 0, rest = 0;

    maxTime = (distances / speed) * 3600; /* From hours to seconds */

    time[0] = (int)maxTime / 3600;
    rest = (int)maxTime % 3600;
    time[1] = rest / 60;
    rest = rest % 60;
    time[2] = rest;

    return time;
}

void findRoute(Stations *s, int start, int end)
{
    int i, j, k, l, m, n, path = 0;
    double shortest_path, complete_path = 0.0;
    int Current_Connections[3], route_taken[AMOUNT_OF_STATIONS];
    double distance[AMOUNT_OF_STATIONS - 1], straightdistance[AMOUNT_OF_STATIONS-1];
    Station t;
    for(t = Aalborg; t < Koebenhavn; t++)
        straightdistance[t] = calculateDistance(s[t].Latitude, s[t].Longitude, s[end].Latitude, s[end].Longitude); /* Calculates distance for every station to end station */
    for (t = Aalborg; t < Koebenhavn; t++)
        distance[t] = calculateDistance(s[t].Latitude, s[t].Longitude, s[t + 1].Latitude, s[t + 1].Longitude); /* Calculates distance between stations  */

    memset(&route_taken,infinite, sizeof(route_taken));
    start = j;
    while (j != end )
    {
        memset(&Current_Connections,infinite, sizeof(Current_Connections));
        
        while (s[j].Connections[i] != infinite) /* Ser efter de connections stationen har, så længe det ikke er NULL */
        {
            s[j].Connections[i] = Current_Connections[i++];
        }
        
        i = 0;
        l = infinite;
        m = infinite;
        n = infinite;
        while(Current_Connections[i] != infinite) /* lægger længden af straightdistance og distance sammen på de stationer som er connected*/
        {
            k = Current_Connections[i++];
            if (i = 0)
                 l = straightdistance[k] + distance[k];
            else if (i = 1)
                m = straightdistance[k] + distance[k];
            else if (i = 2)
                n = Current_Connections[k] + distance[k];
        }
        shortest_path = 0;
        for (i = 0; i < 3; i++)         /* Ser efter hvilken af de connections er kortest*/
        {
            if (l != infinite && shortest_path > l)
                shortest_path = l;
            else if (m != infinite && shortest_path > m)
                shortest_path = m;
            else if (n != infinite && shortest_path > n)
                shortest_path = n;
        }
        complete_path += shortest_path; /* Lægger længden af shortest_path oveni complete_path*/
        route_taken[path] = j;          /*Ligger stationen med den korteste path ind i et array*/
        j = ?;
           
    }
}

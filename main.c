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

#define AMOUNT_OF_STATIONS 27
#define AMOUNT_OF_TRAINS 10
#define MAX_AMOUNT_OF_STATIONS 99

typedef enum Station
{
    Aalborg = 0, Skalborg, Svenstrup, Stoevring, Skoerping, 
    Arden, Hobro, Randers, Langaa, Hadsten, Aarhus, Skanderborg,
    Horsens, Vejle, Fredericia, Middelfart, Odense, Langeskov,
    Nyborg, Korsoer, Slagelse, Soroe, Ringsted, Roskilde,
    Hoeje_Taastrup, Valby, Koebenhavn
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
    int Time[3];
} Train;

char *nameOfStation(int station);
void getStations(Stations *s);
void printTop(Stations *s);
void printTable(int *routeTaken, double *distances, Train *t);
void *findRoute(Stations *s, double *distances, int start, int end);
int isInRoute(int *routeTaken, int currentConnection);

int main(void)
{
    Train IC4[AMOUNT_OF_TRAINS];
    int i, j = 0, *route;
    double distances[AMOUNT_OF_STATIONS - 1];
    Stations s[AMOUNT_OF_STATIONS];
    Station t;
    getStations(s);
    for (i = 0; i < AMOUNT_OF_TRAINS; ++i)
    {
        IC4[i].Status = Off;
        IC4[i].Velocity = 180;
        printf("IC4: %d, Status: %d\n", i, IC4[i].Status);
    }
    IC4[0].Status = Enroute;

    calculateTime(1000, 180, IC4[0].Time);

    for (t = Aalborg; t < Koebenhavn; t++)
        distances[t] = calculateDistance(s[t].Latitude, s[t].Longitude, s[t + 1].Latitude, s[t + 1].Longitude); /* Calculates distance between stations  */

    printf("IC4: %d, Status: %d\n", 0, IC4[0].Status);
    printf("Printing table\n");
    printTop(s);

    route = findRoute(s, distances, Koebenhavn, Aalborg);
    printTable(route, distances, IC4);
    
    /*for (i = 0; route[i] != infinite; ++i)
        printf("Station name: %s\n", nameOfStation(route[i]));*/
    
    printf("Press ENTER to close...");
    getchar();
    return EXIT_SUCCESS;
}

char *nameOfStation(int station)
{
    static char *station_array[] = {"Aalborg", "Skalborg", "Svenstrup", "Stoevring", "Skoerping", "Arden", "Hobro",
                                    "Randers", "Langaa", "Hadsten", "Aarhus", "Skanderborg", "Horsens", "Vejle",
                                    "Fredericia", "Middelfart", "Odense", "Langeskov", "Nyborg", "Korsoer", "Slagelse",
                                    "Soroe", "Ringsted", "Roskilde", "Hoeje Taastrup", "Valby", "Koebenhavn"};
    return station_array[station]; /* Initializes array and returns it for a specific one */
}

void printTop(Stations *s)
{
    int i;
    printf("Station:       %-6.5s", s[0].StationName); /* Prints out the first station */
    for (i = 1; i < AMOUNT_OF_STATIONS; i++) /* Prints the rest out */
        printf(" %-6.5s", s[i].StationName);
    printf("\n"); /* Goes to a newline at the end */
}

void printTable(int *routeTaken, double *distances, Train *IC4)
{
    int i, j, Time_start[3];
    Train IC[AMOUNT_OF_TRAINS];
    Time_start[0] = 5; Time_start[1] = 0; Time_start[2] = 0;
    IC4[0].Time[0]=Time_start[0]; IC4[0].Time[1]=Time_start[1];IC4[0].Time[2]=Time_start[2];
    printf("Hours: %d, Minutes %d, Seconds: %d\n", IC4[0].Time[0], IC4[0].Time[1], IC4[0].Time[2]);
    calculateTime(1000, 180, IC4[0].Time);
    printf("Hours: %d, Minutes %d, Seconds: %d\n", IC4[0].Time[0], IC4[0].Time[1], IC4[0].Time[2]);
    for(i = 0; i <= AMOUNT_OF_STATIONS; i++){
        calculateTime(distances[i], IC4[i].Velocity, IC4[i].Time);
        
    }
    for(i = 0; i <= AMOUNT_OF_TRAINS; ++i) {
        printf("Tog nr: %-5d", i);
        for(j= 0; j < AMOUNT_OF_STATIONS; ++j){
           
            printf(" %-6d:%d", a);
        }
        printf("\n");
    }
}

void getStations(Stations *s)
{
    int i, j;
    char connections[10], *token, delim[2] = ",";
    FILE *fp;
    fp = fopen("Stationer.txt", "r"); /* Opens the file Stationer.txt in read mode */
    if (fp == NULL) /* If there is  no content, print this out */
        printf("Stationer.txt not found\n");
    else
    {
        for (i = 0; !feof(fp); i++) /* Runs until end of file */
        {
            fscanf(fp, "%s %lf %lf %[0-9,]\n",
                   s[i].StationName,
                   &s[i].Latitude,
                   &s[i].Longitude,
                   connections);
            token = strtok(connections, delim); /* Gets the first token in string */
            j = 0;
            while (token != NULL) /* Runs until the token is null */
            {
                s[i].Connections[j] = atoi(token); /* Converst the token into an int and puts it in the station */
                token = strtok(NULL, delim);
                ++j;
            }
        }
        fclose(fp); /* Closes the file */
    }
}

void *findRoute(Stations *s, double *distances, int start, int end)
{
    int i = 0, j, k = 0, o, path = 0;
    double shortest_path, m, n, l;
    int Current_Connections[3];
    static int route_taken[MAX_AMOUNT_OF_STATIONS];
    double straightdistance[AMOUNT_OF_STATIONS - 1];
    double max = 0.0;
    Station t;

    for (t = Aalborg; t < Koebenhavn; t++) /* From Aalborg to Copenhagen (enums) where t is less than Copenhagen */
        straightdistance[t] = calculateDistance(s[t].Latitude, s[t].Longitude, s[end].Latitude, s[end].Longitude); /* Calculates distance for every station to end station */

    for (i = 0; i < MAX_AMOUNT_OF_STATIONS; ++i)
        route_taken[i] = infinite;

    j = start;
    while (j != end)
    {
        for (i = 0; i < 3; ++i)
            Current_Connections[i] = infinite;
        i = 0;
        while (s[j].Connections[i] != 99) /* Looks into the connections as long as it isn't 99 */
        {
            Current_Connections[i] = s[j].Connections[i];
            ++i;
        }

        o = 0;
        l = infinite;
        m = infinite;
        n = infinite;

        for (i = 0; Current_Connections[i] != infinite; i++) /* Adds the lengths of straightdistance and distance together that are connected */
        {
            k = Current_Connections[i];
            if (i == 0)
                l = straightdistance[k] + distances[k];
            else if (i == 1)
                m = straightdistance[k] + distances[k];
            else if (i == 2)
                n = Current_Connections[k] + distances[k];
        }

        shortest_path = infinite;
        for (i = 0; i < 3; ++i) /* Finds the shortest path */
        {
            if (l != infinite && shortest_path > l && !isInRoute(route_taken, Current_Connections[0]))
            {
                shortest_path = l;
                o = 0;
            }
            else if (m != infinite && shortest_path > m && !isInRoute(route_taken, Current_Connections[1]))
            {
                shortest_path = m;
                o = 1;
            }
            else if (n != infinite && shortest_path > n && !isInRoute(route_taken, Current_Connections[2]))
            {
                shortest_path = n;
                o = 2;
            }
        }
        route_taken[path++] = j; /* Puts the current station into route_taken */
        if (o >= 0 && o < 3)
            j = Current_Connections[o]; /* Sets j as the current station */
        else
            printf("Error\n");
    }
    route_taken[path++] = j;
    return route_taken;
}

int isInRoute(int *routeTaken, int currentConnection)
{
    int i, j;
    for (i = 0; i < AMOUNT_OF_STATIONS; ++i) /* Goes through everything in routeTaken array */
    {
        if (routeTaken[i] == currentConnection) /* If it gets caught return 1 */
            return 1;
    }
    return 0; /* Else return 0 if there is none */
}

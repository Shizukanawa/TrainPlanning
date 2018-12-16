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
void *findRoute(Stations *s, int start, int end);
int isInRoute(int *routeTaken, int currentConnection);

int main(void)
{
    Train IC4[AMOUNT_OF_TRAINS];
    int i, j = 0, *speed, *ia;
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
    ia = findRoute(s, Koebenhavn, Aalborg);
    for(i = 0; ia[i] != infinite; ++i)
        printf("Station name: %s\n", nameOfStation(ia[i]));
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
                printf("I: %d j: %d, connections: %d\n", i, j, s[i].Connections[j]);
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

void *findRoute(Stations *s, int start, int end)
{
    int i = 0, j, k = 0, o, path = 0;
    double shortest_path, complete_path = 0.0, m, n, l;
    int Current_Connections[3];
    static int route_taken[MAX_AMOUNT_OF_STATIONS];
    double distance[AMOUNT_OF_STATIONS - 1], straightdistance[AMOUNT_OF_STATIONS-1];
    double max = 0.0;
    Station t;
    if (start < end)
    {
        for (t = Aalborg; t < Koebenhavn; t++)
            straightdistance[t] = calculateDistance(s[t].Latitude, s[t].Longitude, s[end].Latitude, s[end].Longitude); /* Calculates distance for every station to end station */
        for (t = Aalborg; t < Koebenhavn; t++)
            distance[t] = calculateDistance(s[t].Latitude, s[t].Longitude, s[t + 1].Latitude, s[t + 1].Longitude); /* Calculates distance between stations  */
    }
    else
    {
        for (t = Koebenhavn; t > Aalborg; t--)
            straightdistance[i++] = calculateDistance(s[t].Latitude, s[t].Longitude, s[end].Latitude, s[end].Longitude); /* Calculates distance for every station to end station */
        i = 0;
        for (t = Koebenhavn; t > Aalborg; t--)
            distance[i++] = calculateDistance(s[t].Latitude, s[t].Longitude, s[t - 1].Latitude, s[t - 1].Longitude); /* Calculates distance between stations  */
    }

    for (i = 0; i < MAX_AMOUNT_OF_STATIONS; ++i)
        route_taken[i] = infinite;
    
    j = start;
    while (j != end)
    {
        if (start < end)
        {
            for (i = 0; i < 3; ++i)
                Current_Connections[i] = infinite;
            i = 0;
            while (s[j].Connections[i] != 99) /* Ser efter de connections stationen har, så længe det ikke er NULL */
            {
               
                printf("Test: %d %d\n", i, s[j].Connections[i]);
                Current_Connections[i] = s[j].Connections[i];
                ++i;
            }
               
            
            o = 0;
            l = infinite;
            m = infinite;
            n = infinite;
            for (i = 0; Current_Connections[i] != infinite; i++) /* lægger længden af straightdistance og distance sammen på de stationer som er connected*/
            {
                k = Current_Connections[i];
                if (i == 0)
                    l = straightdistance[k] + distance[k];
                else if (i == 1)
                    m = straightdistance[k] + distance[k];
                else if (i == 2)
                    n = Current_Connections[k] + distance[k];
                o++;
            }
 
            printf("l: %lf, m: %lf, n: %lf\n", l, m, n);
            if (l != infinite && l < m && l < n && !isInRoute(route_taken, Current_Connections[0]))
            {
                printf("Test l\n");
                shortest_path = l;  
            }
            else if (m != infinite && m < l && m < n && !isInRoute(route_taken, Current_Connections[1]))
            {
                shortest_path = m;
                printf("Test m\n");
            }
            else if (n != infinite && n < l && n < m && !isInRoute(route_taken, Current_Connections[2]))
            {
                shortest_path = n;
                printf("Test n\n");
            }
            complete_path += shortest_path; /* Lægger længden af shortest_path oveni complete_path*/
            printf("Shortest path: %lf\n", shortest_path);
            route_taken[path++] = j; /*Ligger stationen med den korteste path ind i et array*/
            if (o >= 0 && o <= 3)
                j = Current_Connections[o-1];
            else
                printf("Error\n");
        }
        
        else
        {
            for (i = 0; i < 3; ++i)
                Current_Connections[i] = infinite;
            i = 0;
            while (s[j].Connections[i] != 99) /* Ser efter de connections stationen har, så længe det ikke er NULL */
            {
                printf("Test: %d %d\n", i, s[j].Connections[i]);
                Current_Connections[i] = s[j].Connections[i];
                ++i;
            }
            
            o = 0;
            l = infinite;
            m = infinite;
            n = infinite;
            for (i = 0; Current_Connections[i] != infinite; i++) /* lægger længden af straightdistance og distance sammen på de stationer som er connected*/
            {
                k = Current_Connections[i];
                if (i == 0)
                    l = straightdistance[k] + distance[k];
                else if (i == 1)
                    m = straightdistance[k] + distance[k];
                else if (i == 2)
                    n = Current_Connections[k] + distance[k];
                o++;
            }
            printf("l: %lf, m: %lf, n: %lf\n", l, m, n);
            if (l != infinite && l < m && l < n && !isInRoute(route_taken, Current_Connections[0]))
            {
                printf("Test l\n");
                shortest_path = l;
                
            }
            else if (m != infinite && m < l && m < n && !isInRoute(route_taken, Current_Connections[1]))
            {
                shortest_path = m;
                printf("Test m\n");
                
            }
            else if (n != infinite && n < l && n < m && !isInRoute(route_taken, Current_Connections[2]))
            {
                shortest_path = n;
                printf("Test n\n");
                
            }
            complete_path += shortest_path; /* Lægger længden af shortest_path oveni complete_path*/
            printf("Shortest path: %lf\n", shortest_path);
            route_taken[path++] = j; /*Ligger stationen med den korteste path ind i et array*/
            if (o >= 1 && o <= 3)
                j = Current_Connections[o - 1];
            else
                printf("Error\n");
        }
    }
     route_taken[path++] = j;
     return route_taken;
}


int isInRoute(int *routeTaken, int currentConnection)
{
    int i, j;
    for(i = 0; i < AMOUNT_OF_STATIONS; ++i)
    {
        if(routeTaken[i] == currentConnection)
            return 1;
    }
    return 0;
}

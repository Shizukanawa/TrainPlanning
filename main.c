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

/* Point1: 57.043243, 9.917183 */
/* Point2: 57.008360, 9.898382 */

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
    printf("Result: %lf\n", calculateDistance(57.043243, 9.917183, 57.008360, 9.898382));
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
    double R = 6371000, a, c, Phi1, Phi2, DeltaPhi, DeltaLambda; /* Formular from https://www.movable-type.co.uk/scripts/latlong.html */
    Phi1 = calculateRad(lat1);
    Phi2 = calculateRad(lat2);
    DeltaPhi = calculateRad(lat2 - lat1);
    DeltaLambda = calculateRad(long2 - long1);
    a = sin(DeltaPhi/2) * sin(DeltaPhi/2) +
        cos(Phi1) * cos(Phi2) *
        sin(DeltaLambda/2) * sin(DeltaLambda/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

double calculateRad(double degrees)
{
    return degrees * M_PI / 180;
}
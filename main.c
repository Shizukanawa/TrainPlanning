#include <stdio.h>
#include <stdlib.h>
const int AMOUNT_OF_TRAINS = 10;
enum Status
{
    Off = 1,
    OnRoute,
    Down
};

typedef struct Train
{
    double Velocity;
    int Status;
    double Latitude;
    double Longitude;
} Train;

int main(void)
{
    

    return EXIT_SUCCESS;
}


#include <math.h>
#include <stdlib.h>

double calculateRad(double degrees)
{
    return degrees * M_PI / 180;
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
    c = 2 * sin(fmin(1, sqrt(a)));
    return R * c/1000;
}

int calculateTime(double distances, int velocity, int *time)
{
    double maxTime;
    int hours = 0, rest = 0;

    maxTime = (distances / velocity) * 3600; /* From hours to seconds */

    time[0] = (int)maxTime / 3600; /* Puts the amount of hours into seconds */
    rest = (int)maxTime % 3600; /* Gets the rest and puts it into rest */
    time[1] = rest / 60; /* Takes the rest divided by 60 to convert the rest of hours into minutes */
    time[2] = rest % 60; /* Takes the of minutes and puts it into seconds */
}
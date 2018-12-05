#include <math.h>

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
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c/1000;
}
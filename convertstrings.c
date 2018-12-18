#include <string.h>

enum Station
{
    Aalborg = 0, Skalborg, Svenstrup, Stoevring, Skoerping, 
    Arden, Hobro, Randers, Langaa, Hadsten, Aarhus, Skanderborg,
    Horsens, Vejle, Fredericia, Middelfart, Odense, Langeskov,
    Nyborg, Korsoer, Slagelse, Soroe, Ringsted, Roskilde,
    Hoeje_Taastrup, Valby, Koebenhavn
};

int nameToNumber(char *string)
{
    if (strcmp(string, "Aalborg") == 0)
        return Aalborg;
    else if (strcmp(string, "Skalborg") == 0)
        return Skalborg;
    else if (strcmp(string, "Svenstrup") == 0)
        return Svenstrup;
    else if (strcmp(string, "Stoevring") == 0)
        return Stoevring;
    else if (strcmp(string, "Skoerping") == 0)
        return Skoerping;
    else if (strcmp(string, "Arden") == 0)
        return Arden;
    else if (strcmp(string, "Hobro") == 0)
        return Hobro;
    else if (strcmp(string, "Randers") == 0)
        return Randers;
    else if (strcmp(string, "Langaa") == 0)
        return Langaa;
    else if (strcmp(string, "Hadsten") == 0)
        return Hadsten;
    else if (strcmp(string, "Aarhus") == 0)
        return Aarhus;
    else if (strcmp(string, "Skanderborg") == 0)
        return Skanderborg;
    else if (strcmp(string, "Horsens") == 0)
        return Horsens;
    else if (strcmp(string, "Vejle") == 0)
        return Vejle;
    else if (strcmp(string, "Fredericia") == 0)
        return Fredericia;
    else if (strcmp(string, "Middelfart") == 0)
        return Middelfart;
    else if (strcmp(string, "Odense") == 0)
        return Odense;
    else if (strcmp(string, "Langeskov") == 0)
        return Langeskov;
    else if (strcmp(string, "Nyborg") == 0)
        return Nyborg;
    else if (strcmp(string, "Korsoer") == 0)
        return Korsoer;
    else if (strcmp(string, "Slagelse") == 0)
        return Slagelse;
    else if (strcmp(string, "Soroe") == 0)
        return Soroe;
    else if (strcmp(string, "Ringsted") == 0)
        return Ringsted;
    else if (strcmp(string, "Roskilde") == 0)
        return Roskilde;
    else if (strcmp(string, "Hoeje Taastrup") == 0)
        return Hoeje_Taastrup;
    else if (strcmp(string, "Valby") == 0)
        return Valby;
    else if (strcmp(string, "Koebenhavn") == 0)
        return Koebenhavn;
    else return 99;
}
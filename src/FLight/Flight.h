#ifndef _FLIGHT_
#define _FLIGHT_

typedef struct
{
    char destination[50];
    char departurePoint[50];
    char departureTime[8];
    char landingTime[8];
    char airlineBrand[50];
    int travelTime;
    char status[20];
} Flight;

void addFlight(Flight *flights, int *totalFlights);
void deleteFlight(Flight *flights, int *totalFlights);
void changeFlight(Flight *flights);
void writeFlightToFile(Flight *flights, int totalFlights);
void readFlightFromFile(Flight *flights, int *totalFlights);
void displayFlights(Flight *flights, int totalFlights);
void menuFlights(Flight *flights, int *totalFlights);

#endif

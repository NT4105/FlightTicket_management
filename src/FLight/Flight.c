#include "Flight.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define FLIGHT_FILE_PATH "database\\Flights.txt"

int calculateTravelTime(char *departureTime, char *landingTime)
{
    int hour = (int)(landingTime[0] - departureTime[0]) * 10 + (int)(landingTime[1] - departureTime[1]);
    int minute = (int)(landingTime[3] - departureTime[3]) * 10 + (int)(landingTime[4] - departureTime[4]);

    return hour * 60 + minute;
}

void addFlight(Flight *flights, int *totalFlights)
{
    printf("Enter the flight's departure point: ");
    scanf("%*c%19[^\n]", &flights[*totalFlights].departurePoint);
    printf("Enter the flight's destination: ");
    scanf("%*c%19[^\n]", &flights[*totalFlights].destination);
    printf("Enter the flight's departure time (hh:mm): ");
    scanf("%*c%19[^\n]", &flights[*totalFlights].departureTime);
    printf("Enter the flight's landing time (hh:mm): ");
    scanf("%*c%19[^\n]", &flights[*totalFlights].landingTime);
    printf("Enter the flight's airline brand: ");
    scanf("%*c%19[^\n]", &flights[*totalFlights].airlineBrand);
    printf("Enter the flight's status: ");
    scanf("%*c%19[^\n]", &flights[*totalFlights].status);

    flights[*totalFlights].travelTime = calculateTravelTime(flights[*totalFlights].departureTime, flights[*totalFlights].landingTime);

    (*totalFlights)++;
}

void deleteFlight(Flight *flights, int *totalFlights)
{
    int option;
    printf("Enter flight's ID to delete: ");
    scanf("%d", &option);

    for (int i = option; i < *totalFlights - 1; i++)
    {
        strcpy(flights[i].departurePoint, flights[i + 1].departurePoint);
        strcpy(flights[i].destination, flights[i + 1].destination);
        strcpy(flights[i].departureTime, flights[i + 1].departureTime);
        strcpy(flights[i].landingTime, flights[i + 1].landingTime);
        strcpy(flights[i].airlineBrand, flights[i + 1].airlineBrand);
        flights[i].travelTime = flights[i + 1].travelTime;
        strcpy(flights[i].status, flights[i + 1].status);
    }

    (*totalFlights)--;
}

void changeFlight(Flight *flights)
{
    int option;
    printf("Enter flight's ID to change: ");
    scanf("%d", &option);

    printf("Enter the flight's departure point: ");
    scanf("%*c%50[^\n]", &flights[option].departurePoint);
    printf("Enter the flight's destination: ");
    scanf("%*c%50[^\n]", &flights[option].destination);
    printf("Enter the flight's departure time (hh:mm): ");
    scanf("%*c%8[^\n]", &flights[option].departureTime);
    printf("Enter the flight's landing time (hh:mm): ");
    scanf("%*c%8[^\n]", &flights[option].landingTime);
    printf("Enter the flight's airline brand: ");
    scanf("%*c%50[^\n]", &flights[option].airlineBrand);
    printf("Enter the flight's status: ");
    scanf("%*c%20[^\n]", &flights[option].status);

    flights[option].travelTime = calculateTravelTime(flights[option].departureTime, flights[option].destination);
}

void writeFlightToFile(Flight *flights, int totalFights)
{
    FILE *fp;
    fp = fopen(FLIGHT_FILE_PATH, "wb");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", FLIGHT_FILE_PATH);
        return;
    }

    fwrite(flights, sizeof(Flight), totalFights, fp);
    printf("\nData have been saved!!!");
    Sleep(750);
    fclose(fp);
}

void readFlightFromFile(Flight *flights, int *totalFlights)
{
    FILE *fp;
    fp = fopen(FLIGHT_FILE_PATH, "rb");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", FLIGHT_FILE_PATH);
        return;
    }

    *totalFlights = fread(flights, sizeof(Flight), 100, fp);
    fclose(fp);
}

void displayFlights(Flight *flights, int totalFlights)
{
    char menuComponent[] = "ID Departure-Point  Destination  Departure-Time  Landing-Time  Airline-Brand  Travel-Time(min)  Status         ";

    printf("AirLine Managment > Flight\n\n");

    for (int i = 0; i < strlen(menuComponent); i++)
        printf("=");

    printf("\n%s\n", menuComponent);

    if (totalFlights == 0)
        printf("\n.. ...              ...          ...             ...           ...            ...               ...\n");

    printf("\n");
    for (int i = 0; i < totalFlights; i++)
    {
        printf("%d  %-15s  %-11s  %-14s  %-12s  %-13s  %-16d  %-15s \n",
               i,
               flights[i].departurePoint,
               flights[i].destination,
               flights[i].departureTime,
               flights[i].landingTime,
               flights[i].airlineBrand,
               flights[i].travelTime,
               flights[i].status);
    }

    for (int i = 0; i < strlen(menuComponent); i++)
        printf("=");
    printf("\n");
}

void menuFlights(Flight *flights, int *totalFlights)
{
    readFlightFromFile(flights, totalFlights);
    int loop = 1;
    int isDataSave = 1;
    while (loop)
    {
        displayFlights(flights, *totalFlights);

        char option;

        printf("\n1. Add flight\n");
        printf("2. Delete flight\n");
        printf("3. Change flight\n");
        printf("4. Save data\n");
        printf("5. Back\n");
        while ((getchar()) != '\n')
            ;

        if (isDataSave == 0)
            printf("\nData has been change!! Please save data.\n");

        printf("\nEnter option: ");
        scanf("%c", &option);

        if (option == '1' || option == '2' || option == '3')
            isDataSave = 0;

        switch (option)
        {
        case '1':
            addFlight(flights, totalFlights);
            break;
        case '2':
            deleteFlight(flights, totalFlights);
            break;
        case '3':
            changeFlight(flights);
            break;
        case '4':
            writeFlightToFile(flights, *totalFlights);
            isDataSave = 1;
            break;
        case '5':
            loop = 0;
            break;
        default:
            printf("Wrong syntax!!! Please press any key to choose again.\n");
            Sleep(750);
            break;
        }
        system("Cls");
    }
}

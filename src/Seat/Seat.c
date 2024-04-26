#include "Seat.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define SEAT_FILE_PATH "database\\Seats.txt"

void addSeat(Seat *seats, int *totalSeats)
{
    printf("Enter seat's number: ");
    scanf("%*c%5[^\n]", &seats[*totalSeats].number);
    printf("Enter seat's flightID: ");
    scanf("%*c%30[^\n]", &seats[*totalSeats].flightID);
    printf("Enter seat's status: ");
    scanf("%*c%20[^\n]", &seats[*totalSeats].status);

    (*totalSeats)++;
}

void deleteSeat(Seat *seats, int *totalSeats)
{
    int option;
    printf("Enter seat's ID to delete: ");
    scanf("%d", &option);

    for (int i = option; i < *totalSeats - 1; i++)
    {
        strcpy(seats[i].number, seats[i + 1].number);
        strcpy(seats[i].flightID, seats[i + 1].flightID);
        strcpy(seats[i].status, seats[i + 1].status);
    }

    (*totalSeats)--;
}

void changeSeat(Seat *seats)
{
    int option;
    printf("Enter seat's ID to change: ");
    scanf("%d", &option);

    printf("Enter seat's number: ");
    scanf("%s", &seats[option].number);
    printf("Enter ticket's flightID: ");
    scanf("%s", &seats[option].flightID);
    printf("Enter ticket's status: ");
    scanf("%s", &seats[option].status);
}

void writeSeatToFile(Seat *seats, int totalSeats)
{
    FILE *fp;
    fp = fopen(SEAT_FILE_PATH, "wb");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", SEAT_FILE_PATH);
        return;
    }

    fwrite(seats, sizeof(Seat), totalSeats, fp);
    printf("\nData have been saved!!!");
    Sleep(750);
    fclose(fp);
}

void readSeatFromFile(Seat *seats, int *totalSeats)
{
    FILE *fp;
    fp = fopen(SEAT_FILE_PATH, "rb");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", SEAT_FILE_PATH);
        return;
    }

    *totalSeats = fread(seats, sizeof(Seat), 100, fp);
    fclose(fp);
}

void displaySeats(Seat *seats, int totalSeats)
{
    char menuComponent[] = "ID Number         Flight-ID       Status   ";

    printf("AirLine Managment > Seat\n\n");

    for (int i = 0; i < strlen(menuComponent); i++)
        printf("=");

    printf("\n%s\n", menuComponent);

    if (totalSeats == 0)
        printf("\n.. ...            ...             ...\n");

    printf("\n");
    for (int i = 0; i < totalSeats; i++)
    {
        printf("%d  %-15s %-15s %-9s\n",
               i,
               seats[i].number,
               seats[i].flightID,
               seats[i].status);
    }

    for (int i = 0; i < strlen(menuComponent); i++)
        printf("=");
    printf("\n");
}

void menuSeats(Seat *seats, int *totalSeats)
{
    readSeatFromFile(seats, totalSeats);
    int loop = 1;
    int isDataSave = 1;
    while (loop)
    {
        displaySeats(seats, *totalSeats);

        char option;

        printf("\n1. Add Seat\n");
        printf("2. Delete Seat\n");
        printf("3. Change Seat\n");
        printf("4. Save data\n");
        printf("5. Exit\n");
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
            addSeat(seats, totalSeats);
            break;
        case '2':
            deleteSeat(seats, totalSeats);
            break;
        case '3':
            changeSeat(seats);
            break;
        case '4':
            writeSeatToFile(seats, *totalSeats);
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
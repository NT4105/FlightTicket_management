#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seat.h"
#include <windows.h>

#define MAX_SEATS 50
#define SEAT_FILE_PATH "database\\Seats.txt"

void writeSeatFile(Seat seats[], int totalSeats) {
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

void readSeatFile(Seat seats[], int *totalSeats) {
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

void addSeat(Seat seats[], int *totalSeats) {
    if (*totalSeats >= MAX_SEATS) {
        printf("The flight is full.\n");
        return;
    }

    printf("Enter seat's number: ");
    scanf("%*c%5[^\n]", &seats[*totalSeats].number);
    printf("Enter seat's flightID: ");
    scanf("%*c%30[^\n]", &seats[*totalSeats].flightID);
    printf("Enter seat's status: ");
    scanf("%*c%20[^\n]", &seats[*totalSeats].status);

    (*totalSeats)++;
}

void deleteSeat(Seat seats[], int *totalSeats) {
    int option;
    printf("Enter seat's ID to delete: ");
    scanf("%d", &option);

    for (int i = 0; i < *totalSeats; i++) {
        if (seats[i].number == option) {
            for (int j = i; j < totalSeats - 1; j++) {
                seats[j] = seats[j + 1];
            }
            totalSeats--;
            printf("Delete seat's ID successfully.\n");
            return;
        }
    }

    printf("Seat's ID can't be found.\n");
}

void changeSeat(Seat seats[]) {
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

void displaySeats(Seat seats[], int totalSeats) {
    printf("\n=== LIST OF SEAT ===\n");
    printf("Seat's number.\tSeat's flightID.\tSeat's status\n");
    for (int i = 0; i < totalSeats; i++) {
        printf("%d\t\t%d\t\t%s\n", seats[i].number, seats[i].flightID, seats[i].status ? "Co" : "Khong");
    }
    printf("====================\n");
}

void menuSeats(Seat seats[], int *totalSeats)
{
    readSeatFile(seats, totalSeats);
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

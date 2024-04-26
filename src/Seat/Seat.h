#ifndef AIRPLANE_SEAT_MANAGEMENT_H
#define AIRPLANE_SEAT_MANAGEMENT_H

typedef struct
{
    char number[5];
    char flightID[30];
    char status[20];
} Seat;

void addSeat(Seat seats[], int *totalSeats);
void deleteSeat(Seat seats[], int *totalSeats);
void changeSeat(Seat seats[]);
void writeSeatFile(Seat seats[], int totalSeats);
void readSeatFile(Seat seats[], int *totalSeats);
void displaySeats(Seat seats[], int totalSeats);
void menuSeats(Seat seats[], int *totalSeats);


#endif

#ifndef _SEAT_
#define _SEAT_

typedef struct
{
    char number[5];
    char flightID[30];
    char status[20];
} Seat;

void addSeat(Seat *seats, int *totalSeats);
void deleteSeat(Seat *seats, int *totalSeats);
void changeSeat(Seat *seats);
void writeSeatToFile(Seat *seats, int totalSeats);
void readSeatFromFile(Seat *seats, int *totalSeats);
void displaySeats(Seat *seats, int totalSeats);
void menuSeats(Seat *seats, int *totalSeats);

#endif
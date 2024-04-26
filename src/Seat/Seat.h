#ifndef AIRPLANE_SEAT_MANAGEMENT_H
#define AIRPLANE_SEAT_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 100

struct Seat {
    int seatNumber;
    int flightNumber;
    int booked;
};

void saveToFile(struct Seat seats[], int numSeats);
void loadFromFile(struct Seat seats[], int *numSeats);
void addSeat(struct Seat seats[], int *numSeats);
void deleteSeat(struct Seat seats[], int *numSeats);
void editSeat(struct Seat seats[], int numSeats);
void displaySeats(struct Seat seats[], int numSeats);
void menuSeat(struct Seat seats[], int numSeats)
#endif 

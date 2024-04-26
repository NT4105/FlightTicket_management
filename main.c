#include "src\FLight\Flight.h"
#include "src\Ticket\Ticket.h"
#include "src\Buyer\Buyer.h"
#include "src\Seat\Seat.h"
#include <stdio.h>
#include <windows.h>

#define MAX_FLIGHT 100
#define MAX_TICKET 100
#define MAX_BUYER 100
#define MAX_SEAT 100

int main()
{
    Flight flights[MAX_FLIGHT];
    Ticket tickets[MAX_TICKET];
    Buyer buyer[MAX_BUYER];
    Seat seats[MAX_SEAT];

    int totalFlights = 0;
    int totalTickets = 0;
    int totalBuyers = 0;
    int totalSeats = 0;

    int loop = 1;
    while (loop)
    {
        printf("AirLine Managment\n\n");
        printf("1. Flights\n");
        printf("2. Tickets\n");
        printf("3. Seats\n");
        printf("4. Buyers\n");
        printf("5. Exit\n\n");

        int option;
        printf("Enter option: ");
        scanf("%d", &option);
        system("Cls");

        switch (option)
        {
        case 1:
            menuFlights(flights, &totalFlights);
            break;
        case 2:
            menuTickets(tickets, &totalTickets);
            break;
        case 3:
            menuSeats(seats, &totalSeats);
            break;
        case 4:
            menuBuyers(buyer, &totalBuyers);
            break;
        case 5:
            loop = 0;
            break;
        }
        system("Cls");
    }

    return 0;
}
#ifndef _TICKET_
#define _TICKET_

typedef struct
{
    char customerName[30];
    char registorTime[12];
    char price[10];
    char type[15];
    char planeID[10];
    char seatNumber[5];
} Ticket;

void addTicket(Ticket *tickets, int *totalTickets);
void deleteTicket(Ticket *tickets, int *totalTickets);
void writeTicketToFile(Ticket *tickets, int totalTickets);
void readTicketFromFile(Ticket *tickets, int *totalTickets);
void displayTickets(Ticket *tickets, int totalTickets);
void menuTickets(Ticket *tickets, int *totalTickets);

#endif

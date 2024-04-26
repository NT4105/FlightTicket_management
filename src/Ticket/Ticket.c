#include "Ticket.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TICKET_FILE_PATH "database\\Tickets.txt"

void addTicket(Ticket *tickets, int *totalTickets)
{
    printf("Enter ticket's customer name: ");
    scanf("%*c%30[^\n]", &tickets[*totalTickets].customerName);
    printf("Enter ticket's registor time (hh:mm): ");
    scanf("%*c%8[^\n]", &tickets[*totalTickets].registorTime);
    printf("Enter ticket's price: ");
    scanf("%*c%10[^\n]", &tickets[*totalTickets].price);
    printf("Enter ticket's type: ");
    scanf("%*c%15[^\n]", &tickets[*totalTickets].type);
    printf("Enter ticket's plane ID: ");
    scanf("%*c%10[^\n]", &tickets[*totalTickets].planeID);
    printf("Enter ticket's seat number: ");
    scanf("%*c%5[^\n]", &tickets[*totalTickets].seatNumber);

    (*totalTickets)++;
}

void deleteTicket(Ticket *tickets, int *totalTickets)
{
    int option;
    printf("Enter ticket's ID to delete: ");
    scanf("%d", &option);

    for (int i = option; i < *totalTickets - 1; i++)
    {
        strcpy(tickets[i].customerName, tickets[i + 1].customerName);
        strcpy(tickets[i].registorTime, tickets[i + 1].registorTime);
        strcpy(tickets[i].price, tickets[i + 1].price);
        strcpy(tickets[i].type, tickets[i + 1].type);
        strcpy(tickets[i].planeID, tickets[i + 1].planeID);
        strcpy(tickets[i].seatNumber, tickets[i + 1].seatNumber);
    }

    (*totalTickets)--;
}

void writeTicketToFile(Ticket *tickets, int totalTickets)
{
    FILE *fp;
    fp = fopen(TICKET_FILE_PATH, "wb");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", TICKET_FILE_PATH);
        return;
    }

    fwrite(tickets, sizeof(Ticket), totalTickets, fp);
    printf("\nData have been saved!!!");
    Sleep(750);
    fclose(fp);
}

void readTicketFromFile(Ticket *tickets, int *totalTickets)
{
    FILE *fp;
    fp = fopen(TICKET_FILE_PATH, "rb");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", TICKET_FILE_PATH);
        return;
    }

    *totalTickets = fread(tickets, sizeof(Ticket), 100, fp);
    fclose(fp);
}

void displayTickets(Ticket *tickets, int totalTickets)
{
    char menuComponent[] = "ID Customer-name   Registor-Time   Price      Type        Plane-ID   Seat-Number";

    printf("AirLine Managment > Tickets\n\n");

    for (int i = 0; i < strlen(menuComponent); i++)
        printf("=");

    printf("\n%s\n", menuComponent);

    if (totalTickets == 0)
        printf("\n.. ...             ...             ...        ...         ...        ...\n");

    printf("\n");
    for (int i = 0; i < totalTickets; i++)
    {
        printf("%d  %-15s %-15s $%-9s %-11s %-14s %-12s \n",
               i,
               tickets[i].customerName,
               tickets[i].registorTime,
               tickets[i].price,
               tickets[i].type,
               tickets[i].planeID,
               tickets[i].seatNumber);
    }

    for (int i = 0; i < strlen(menuComponent); i++)
        printf("=");
    printf("\n");
}

void menuTickets(Ticket *tickets, int *totalTickets)
{
    int loop = 1;
    int isDataSave = 1;
    while (loop)
    {
        displayTickets(tickets, *totalTickets);
        char option;

        printf("\n1. Add ticket\n");
        printf("2. Delete ticket\n");
        printf("3. Save data\n");
        printf("4. Exit\n");
        while ((getchar()) != '\n')
            ;

        if (isDataSave == 0)
            printf("\nData has been change!! Please save data.\n");

        printf("\nEnter option: ");
        scanf("%c", &option);

        if (option == '1' || option == '2')
            isDataSave = 0;

        switch (option)
        {
        case '1':
            addTicket(tickets, totalTickets);
            break;
        case '2':
            deleteTicket(tickets, totalTickets);
            break;
        case '3':
            writeTicketToFile(tickets, *totalTickets);
            isDataSave = 1;
            break;
        case '4':
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

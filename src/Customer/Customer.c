#include "Customer.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define CUSTOMER_FILE_PATH "database\\Customers.txt"

void changeCustomer(Customer *customers)
{
    int option;
    printf("Enter customer's ID to change: ");
    scanf("%d", &option);

    printf("Enter the customer's ID number: ");
    scanf("%*c%12[^\n]", &customers[option].idNumber);
    printf("Enter the customer's name: ");
    scanf("%*c%30[^\n]", &customers[option].name);
    printf("Enter the customer's phone number: ");
    scanf("%*c%12[^\n]", &customers[option].phoneNumber);
    printf("Enter the customer's mail: ");
    scanf("%*c%30[^\n]", &customers[option].mail);
}

void writeCustomerToFile(Customer *customers, int totalCustomers)
{
    FILE *fp;
    fp = fopen(CUSTOMER_FILE_PATH, "wb");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", CUSTOMER_FILE_PATH);
        return;
    }

    fwrite(customers, sizeof(Customer), totalCustomers, fp);
    printf("\nData have been saved!!!");
    Sleep(750);
    fclose(fp);
}

void readCustomerFromFile(Customer *customers, int *totalCustomers)
{
    FILE *fp;
    fp = fopen(CUSTOMER_FILE_PATH, "rb");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", CUSTOMER_FILE_PATH);
        return;
    }

    *totalCustomers = fread(customers, sizeof(Customer), 100, fp);
    fclose(fp);
}

void displayCustomers(Customer *customers, int totalCustomers)
{
    char menuComponent[] = "ID ID-Number    Name           Phone-Number   Mail                          ";

    printf("AirLine Managment > Customer\n\n");

    for (int i = 0; i < strlen(menuComponent); i++)
        printf("=");

    printf("\n%s\n", menuComponent);

    if (totalCustomers == 0)
        printf("\n.. ...          ...            ...            ...\n");

    printf("\n");
    for (int i = 0; i < totalCustomers; i++)
    {
        printf("%d  %-12s %-15s %-14s %-15s %-30s  \n",
               i,
               customers[i].idNumber,
               customers[i].name,
               customers[i].phoneNumber,
               customers[i].mail);
    }

    for (int i = 0; i < strlen(menuComponent); i++)
        printf("=");
    printf("\n");
}

void menuCustomers(Customer *customers, int *totalCustomers)
{
    readCustomerFromFile(customers, totalCustomers);
    int loop = 1;
    int isDataSave = 1;
    while (loop)
    {
        displayCustomers(customers, *totalCustomers);

        char option;

        printf("\n1. Change Customer Info\n");
        printf("2. Save data\n");
        printf("3. Exit\n");
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
            changeCustomer(customers);
            break;
        case '2':
            writeCustomerToFile(customers, *totalCustomers);
            isDataSave = 1;
            break;
        case '3':
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
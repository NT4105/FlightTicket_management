#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Buyer.h"
#include <windows.h>

#define MAX_LENGTH 50
#define BUYER_FILE_PATH "database\\Buyers.txt"


void addBuyer(Buyer buyer[], int *totalBuyers) {
    printf("Enter the buyer's CCCD: ");
    scanf("%s", &buyer[*totalBuyers].CCCD);
    printf("Enter the buyer's name: ");
    scanf("%*c%19[^\n]", &buyer[*totalBuyers].name);          //đọc vào cả chuỗi (bao gồm dấu cách), chỉ dừng khi gặp \n
    printf("Enter the buyer's phone number: ");
    scanf("%s", &buyer[*totalBuyers].sdt);
    printf("Enter the buyer's mail (or not): ");
    scanf("%*c%19[^\n]", &buyer[*totalBuyers].mail);
    (totalBuyers)++;
}

void displayBuyer(Buyer buyer[], int totalBuyers) {
    for (int i = 0; i < totalBuyers; i++) {
        printf("======Information of buyer=====\n");
        printf("CCCD: %s\n", buyer[i].CCCD);
        printf("Buyer's name: %s\n", buyer[i].name);
        printf("Buyer's number phone: %s\n", buyer[i].sdt);
        printf("Buyer's address mail: %s\n", buyer[i].mail);
    }
}

void changeBuyer(Buyer buyer[], int pos) {
        printf("Enter the buyer's CCCD: ");
        scanf("%s", &buyer[pos].CCCD);
        printf("Enter the buyer's name: ");
        scanf("%*c%19[^\n]", &buyer[pos].name);          //đọc vào cả chuỗi (bao gồm dấu cách), chỉ dừng khi gặp \n
        printf("Enter the buyer's phone number: ");
        scanf("%s", &buyer[pos].sdt);
        printf("Enter the buyer's mail (or not): ");
        scanf("%*c%19[^\n]", &buyer[pos].mail);
}

void writeBuyerFile(Buyer buyer[], int totalBuyers) {
    FILE *fp;
    fp = fopen(BUYER_FILE_PATH, "wb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", BUYER_FILE_PATH);
        return;
    }

    fwrite(buyer, sizeof(Buyer), totalBuyers, fp);
    puts("Data have been saved !!!");
    fclose(fp);
}

void readBuyerFile(Buyer buyer[], int *totalBuyers) {
    FILE *fp;
    fp = fopen(BUYER_FILE_PATH, "rb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", BUYER_FILE_PATH);
        return;
    }

    *totalBuyers = fread(buyer, sizeof(Buyer), MAX_LENGTH, fp);
    fclose(fp);
}

void menuBuyers(Buyer buyer[], int *totalBuyers) {
    char option;
    do {
        printf("\n=====INFORMATION THE BUYER=====\n");
        printf("1. Add the buyer info\n");
        printf("2. Show the buyer info\n");
        printf("3. Change/update the buyer info\n");
        printf("4. Save the buyer info to the file\n");
        printf("5. Read the buyer info in the file\n");
        printf("6. Exit\n");
        printf("Choose your option: ");
        scanf("%c", &option);

        switch (option) {
            case '1':
                addBuyer(buyer, totalBuyers);
                break;
            case '2':
                displayBuyer(buyer, *totalBuyers);
                break;
            case '3':
                printf("Enter the position in info: ");
                int pos;
                scanf("%d", &pos);
                if (pos >= 0 && pos < totalBuyers) {
                    changeBuyer(buyer, pos);
                } else {
                    printf("Invaild position.\n");
                }
                break;
            case '4':
                writeBuyerFile(buyer, *totalBuyers);
                break;
            case '5':
                readBuyerFile(buyer, &totalBuyers);
                for (int i = 0; i < totalBuyers; i++) {
                    displayBuyer(buyer, i);
                }
                break;
            case '6':
                break;
            default:
                printf("Wrong syntax!!! Please press any key to choose again.\n");
        }
    } while (option != '6');
    system ("Cls");
}

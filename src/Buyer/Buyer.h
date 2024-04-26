#ifndef BUYER_H
#define BUYER_H

#define MAX_LENGTH 50

typedef struct {
    char CCCD[MAX_LENGTH];
    char name[MAX_LENGTH];
    char sdt[MAX_LENGTH];
    char mail[MAX_LENGTH];
} Buyer;

void addBuyer(Buyer buyer[], int *totalBuyers);
void displayBuyer(Buyer buyer[], int totalBuyers);
void changeBuyer(Buyer buyer[], int pos);
void writeBuyerFile(Buyer buyer[], int totalBuyers);
void readBuyerFile(Buyer buyer[], int *totalBuyers);
void menuBuyers(Buyer buyer[], int *totalBuyers);

#endif
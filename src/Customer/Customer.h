#ifndef _CUSTOMER_
#define _CUSTOMER_

typedef struct
{
    char idNumber[12];
    char name[30];
    char phoneNumber[12];
    char mail[30];
} Customer;

void changeCustomer(Customer *customers);
void writeCustomerToFile(Customer *customers, int totalCustomers);
void readCustomerFromFile(Customer *customers, int *totalCustomers);
void displayCustomers(Customer *customers, int totalCustomers);
void menuCustomers(Customer *customers, int *totalCustomers);

#endif
#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct Customer {
    int id;
    char* name;
    struct Customer* next;
} Customer;

Customer* addCustomer(Customer* head, int id, const char* name);

void displayCustomers(Customer* head);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

Customer* addCustomer(Customer* head, int id, const char* name) {
    Customer* newCust = (Customer*)malloc(sizeof(Customer));
    newCust->id = id;
    newCust->name = strdup(name);
    newCust->next = head;
    return newCust;
}


void displayCustomers(Customer* head) {
    while (head) {
        printf("Customer ID: %d, Name: %s\n", head->id, head->name);
        head = head->next;
    }
}

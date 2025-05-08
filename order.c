#include <stdio.h>
#include <stdlib.h>
#include "order.h"

typedef struct Order {
    int customerId;
    int productId;
    struct Order* next;
} Order;

static Order *front = NULL, *rear = NULL;

void placeOrder(int customerId, int productId) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    newOrder->customerId = customerId;
    newOrder->productId = productId;
    newOrder->next = NULL;
    if (rear == NULL)
        front = rear = newOrder;
    else {
        rear->next = newOrder;
        rear = newOrder;
    }
    printf("Order placed: Customer %d ordered Product %d\n", customerId, productId);
}

void processOrder(void) {
    if (front == NULL) {
        printf("No orders to process.\n");
        return;
    }
    Order* temp = front;
    printf("Processing Order: Customer %d -> Product %d\n", temp->customerId, temp->productId);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

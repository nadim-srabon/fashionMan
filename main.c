#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "customer.h"
#include "order.h"
#include "wishlist.h"

int main() {
    Product* productRoot = NULL;
    Customer* customerHead = NULL;
    int choice;

    while (1) {
        printf("\n========== Fashion Management System ==========\n");
        printf("1. Add Product\t\t2. Display Products\n");
        printf("3. Add Customer\t\t4. Display Customers\n");
        printf("5. Place Order\t\t6. Process Order\n");
        printf("7. Add to Wishlist\t8. View Wishlist\n");
        printf("9. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id, stock;
            float price;
            char tempName[100], tempCategory[100];
            printf("Enter ID, Name, Category, Price, Stock: ");
            scanf("%d %s %s %f %d", &id, tempName, tempCategory, &price, &stock);
            productRoot = addProduct(productRoot, id, tempName, tempCategory, price, stock);
        }
        else if (choice == 2) {
            printf("\n--- Product List ---\n");
            displayProducts(productRoot);
        }
        else if (choice == 3) {
            int id;
            char tempName[100];
            printf("Enter Customer ID and Name: ");
            scanf("%d %s", &id, tempName);
            customerHead = addCustomer(customerHead, id, tempName);
        }
        else if (choice == 4) {
            printf("\n--- Customer List ---\n");
            displayCustomers(customerHead);
        }
        else if (choice == 5) {
            int custId, prodId;
            printf("Enter Customer ID and Product ID: ");
            scanf("%d %d", &custId, &prodId);
            placeOrder(custId, prodId);
        }
        else if (choice == 6) {
            processOrder();
        }
        else if (choice == 7) {
            int prodId;
            printf("Enter Product ID to add to wishlist: ");
            scanf("%d", &prodId);
            pushWishlist(prodId);
        }
        else if (choice == 8) {
            viewWishlist();
        }
        else if (choice == 9) {
            printf("Exiting system. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Optional: free dynamically allocated memory (good practice)


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "customer.h"
#include "order.h"
#include "wishlist.h"

static int lastProductId = 0;

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
            int stock, category, gender, hasMeasurements;
            float price;
            char tempName[100];
            Measurement measurements;

            printf("Enter Product Name: ");
            scanf("%99s", tempName);

            printf("Available Categories:\n");
            for (int i = 0; i <= CAT_OTHER; i++) {
                printf("%d. %s\n", i, categoryToString(i));
            }
            printf("Select Category (0-%d): ", CAT_OTHER);
            scanf("%d", &category);

            printf("Gender (0-Ladies, 1-Gents, 2-Kids, 3-Unisex): ");
            scanf("%d", &gender);

            printf("Enter Price and Stock: ");
            scanf("%f %d", &price, &stock);

            printf("Add measurements? (0-No, 1-Yes): ");
            scanf("%d", &hasMeasurements);

            if (hasMeasurements) {
                printf("Enter Size (e.g., S, M, L): ");
                scanf("%9s", measurements.size);
                printf("Enter Length, Chest, Waist measurements: ");
                scanf("%f %f %f", &measurements.length, &measurements.chest, &measurements.waist);
            }

            // Auto-generate ID
            int id = ++lastProductId;

            productRoot = addProduct(productRoot, id, tempName, category, gender, price, stock,
                                   hasMeasurements ? &measurements : NULL);
            printf("Product added with ID: %d\n", id);
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

    // Free allocated memory (simplified example)
    // In a real application, you would need proper cleanup functions
    // for your BST and linked lists

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "customer.h"
#include "order.h"

static int lastProductId = 0;

void displayFabricOptions(ProductGender gender) {
    printf("Available Fabrics:\n");
    if (gender == GENDER_LADIES) {
        printf("0. Baksi Primit 160\n");
        printf("1. Orbindo Primit 150\n");
        printf("2. Jorget 200\n");
    } else { // For Gents and others
        printf("3. Raymond Cotton 800\n");
        printf("4. Gringa 1000\n");
        printf("5. Orbindo 700\n");
    }
    printf("6. Other Fabric\n");
}

int main() {
    Product* productRoot = NULL;
    Customer* customerHead = NULL;
    int choice;

    while (1) {
        printf("\n========== Fashion Management System ==========\n");
        printf("1. Add Product\t\t2. Display Products\n");
        printf("3. Add Customer\t\t4. Display Customers\n");
        printf("5. Place Order\t\t6. Process Order\n");
        printf("7. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int stock, category, gender, hasMeasurements, fabricChoice;
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

            // Show appropriate fabric options based on gender
            displayFabricOptions(gender);
            printf("Select Fabric: ");
            scanf("%d", &fabricChoice);

            printf("Add measurements? (0-No, 1-Yes): ");
            scanf("%d", &hasMeasurements);

            if (hasMeasurements) {
                if (category == CAT_KAMEEZ) {
                    printf("Enter Kameez measurements (length, shoulder width, sleeve length, neckline, armhole): ");
                    scanf("%f %f %f %f %f", &measurements.k_length, &measurements.k_shoulder_width,
                          &measurements.k_sleeve_length, &measurements.k_neckline, &measurements.k_armhole);
                }
                else if (category == CAT_SHIRT) {
                    printf("Enter Shirt measurements (neck, chest, shoulder, sleeve, waist, length, cuff): ");
                    scanf("%f %f %f %f %f %f %f", &measurements.s_neck_circumference, &measurements.s_chest,
                          &measurements.s_shoulder_width, &measurements.s_sleeve_length,
                          &measurements.s_waist_circumference, &measurements.s_shirt_length,
                          &measurements.s_cuff_circumference);
                }
                else {
                    printf("Enter Size (e.g., S, M, L): ");
                    scanf("%9s", measurements.size);
                    printf("Enter Length, Chest, Waist measurements: ");
                    scanf("%f %f %f", &measurements.length, &measurements.chest, &measurements.waist);
                }
            }

            int id = ++lastProductId;
            productRoot = addProduct(productRoot, id, tempName, category, gender, price, stock,
                                   fabricChoice, hasMeasurements ? &measurements : NULL);
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
            printf("Exiting system. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

static int lastProductId = 0;

const char* categoryToString(ProductCategory cat) {
    static const char* strings[] = {
        "Shirt", "Kurta", "Ponga Blazer", "Sherwani", "Pant",
        "Kameez", "Anandali", "Crown", "Kurdi", "Paigma",
        "Other"
    };
    return strings[cat];
}

const char* genderToString(ProductGender gender) {
    static const char* strings[] = {
        "Ladies", "Gents", "Kids", "Unisex"
    };
    return strings[gender];
}

const char* fabricToString(FabricType fabric) {
    static const char* strings[] = {
        "Baksi Primit 160 (Ladies)",
        "Orbindo Primit 150 (Ladies)",
        "Jorget 200 (Ladies)",
        "Raymond Cotton 800 (Gents)",
        "Gringa 1000 (Gents)",
        "Orbindo 700 (Gents)",
        "Other Fabric"
    };
    return strings[fabric];
}

Product* addProduct(Product* root, int id, const char* name, ProductCategory category,
                   ProductGender gender, float price, int stock, FabricType fabric,
                   const Measurement* measurements) {
    if (root == NULL) {
        Product* newProduct = (Product*)malloc(sizeof(Product));
        newProduct->id = id;
        newProduct->name = strdup(name);
        newProduct->category = category;
        newProduct->gender = gender;
        newProduct->price = price;
        newProduct->stock = stock;
        newProduct->fabric = fabric;

        if (measurements != NULL) {
            newProduct->measurements = *measurements;
            newProduct->hasMeasurements = 1;
        } else {
            newProduct->hasMeasurements = 0;
        }

        newProduct->left = newProduct->right = NULL;
        return newProduct;
    }

    if (id < root->id)
        root->left = addProduct(root->left, id, name, category, gender, price, stock, fabric, measurements);
    else if (id > root->id)
        root->right = addProduct(root->right, id, name, category, gender, price, stock, fabric, measurements);

    return root;
}

void displayProducts(Product* root) {
    if (root != NULL) {
        displayProducts(root->left);
        printf("ID: %d, Name: %s, Category: %s, Gender: %s\n",
               root->id, root->name, categoryToString(root->category),
               genderToString(root->gender));
        printf("Price: %.2f, Stock: %d, Fabric: %s\n",
               root->price, root->stock, fabricToString(root->fabric));

        if (root->hasMeasurements) {
            switch(root->category) {
                case CAT_KAMEEZ:
                    printf("  Measurements: Length: %.1f\", Shoulder: %.1f\", Sleeve: %.1f\", Neck: %.1f\", Armhole: %.1f\"\n",
                           root->measurements.k_length, root->measurements.k_shoulder_width,
                           root->measurements.k_sleeve_length, root->measurements.k_neckline,
                           root->measurements.k_armhole);
                    break;
                case CAT_SHIRT:
                    printf("  Measurements: Neck: %.1f\", Chest: %.1f\", Shoulder: %.1f\", Sleeve: %.1f\", Waist: %.1f\", Length: %.1f\", Cuff: %.1f\"\n",
                           root->measurements.s_neck_circumference, root->measurements.s_chest,
                           root->measurements.s_shoulder_width, root->measurements.s_sleeve_length,
                           root->measurements.s_waist_circumference, root->measurements.s_shirt_length,
                           root->measurements.s_cuff_circumference);
                    break;
                default:
                    printf("  Measurements: Size %s, Length: %.1f\", Chest: %.1f\", Waist: %.1f\"\n",
                           root->measurements.size, root->measurements.length,
                           root->measurements.chest, root->measurements.waist);
            }
        }
        printf("----------------------------------------\n");
        displayProducts(root->right);
    }
}

Product* searchProduct(Product* root, int id) {
    if (root == NULL || root->id == id)
        return root;
    if (id < root->id)
        return searchProduct(root->left, id);
    return searchProduct(root->right, id);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

static int lastProductId = 0;

const char* categoryToString(ProductCategory cat) {
    static const char* strings[] = {
        "Shirt", "Pants", "Dress", "Skirt", "Jacket", "Shoes", "Accessory",
        "Handbag", "Jewelry", "Watch", "Sunglasses", "Hat", "Scarf", "Tie",
        "Belt", "Socks", "Underwear", "Swimwear", "Sportswear", "Coat",
        "Sweater", "Jeans", "Shorts", "T-Shirt", "Blouse", "Suit", "Leggings",
        "Boots", "Sandals", "Other"
    };
    return strings[cat];
}

const char* genderToString(ProductGender gender) {
    static const char* strings[] = {
        "Ladies", "Gents", "Kids", "Unisex"
    };
    return strings[gender];
}

Product* addProduct(Product* root, int id, const char* name, ProductCategory category,
                   ProductGender gender, float price, int stock, const Measurement* measurements) {
    if (root == NULL) {
        Product* newProduct = (Product*)malloc(sizeof(Product));
        newProduct->id = id;
        newProduct->name = strdup(name);
        newProduct->category = category;
        newProduct->gender = gender;
        newProduct->price = price;
        newProduct->stock = stock;

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
        root->left = addProduct(root->left, id, name, category, gender, price, stock, measurements);
    else if (id > root->id)
        root->right = addProduct(root->right, id, name, category, gender, price, stock, measurements);

    return root;
}

void displayProducts(Product* root) {
    if (root != NULL) {
        displayProducts(root->left);
        printf("ID: %d, Name: %s, Category: %s, Gender: %s, Price: %.2f, Stock: %d\n",
               root->id, root->name, categoryToString(root->category),
               genderToString(root->gender), root->price, root->stock);

        if (root->hasMeasurements) {
            printf("  Measurements: Size %s, Length: %.1f, Chest: %.1f, Waist: %.1f\n",
                   root->measurements.size, root->measurements.length,
                   root->measurements.chest, root->measurements.waist);
        }

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

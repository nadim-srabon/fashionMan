#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

Product* addProduct(Product* root, int id, const char* name, const char* category, float price, int stock) {
    if (root == NULL) {
        Product* newProduct = (Product*)malloc(sizeof(Product));
        newProduct->id = id;
        newProduct->name = strdup(name);         // Allocate and copy name
        newProduct->category = strdup(category); // Allocate and copy category
        newProduct->price = price;
        newProduct->stock = stock;
        newProduct->left = newProduct->right = NULL;
        return newProduct;
    }
    if (id < root->id)
        root->left = addProduct(root->left, id, name, category, price, stock);
    else if (id > root->id)
        root->right = addProduct(root->right, id, name, category, price, stock);
    return root;
}

void displayProducts(Product* root) {
    if (root != NULL) {
        displayProducts(root->left);
        printf("ID: %d, Name: %s, Category: %s, Price: %.2f, Stock: %d\n",
               root->id, root->name, root->category, root->price, root->stock);
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

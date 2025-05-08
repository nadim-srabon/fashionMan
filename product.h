#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct Product {
    int id;
    char* name;
    char* category;
    float price;
    int stock;
    struct Product *left, *right;
} Product;

Product* addProduct(Product* root, int id, const char* name, const char* category, float price, int stock);
void displayProducts(Product* root);
Product* searchProduct(Product* root, int id);

#endif

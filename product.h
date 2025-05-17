#ifndef PRODUCT_H
#define PRODUCT_H

typedef enum {
    CAT_SHIRT,
    CAT_PANTS,
    CAT_DRESS,
    CAT_SKIRT,
    CAT_JACKET,
    CAT_SHOES,
    CAT_ACCESSORY,
    CAT_HANDBAG,
    CAT_JEWELRY,
    CAT_WATCH,
    CAT_SUNGLASSES,
    CAT_HAT,
    CAT_SCARF,
    CAT_TIE,
    CAT_BELT,
    CAT_SOCKS,
    CAT_UNDERWEAR,
    CAT_SWIMWEAR,
    CAT_SPORTSWEAR,
    CAT_COAT,
    CAT_SWEATER,
    CAT_JEANS,
    CAT_SHORTS,
    CAT_TSHIRT,
    CAT_BLOUSE,
    CAT_SUIT,
    CAT_LEGGINGS,
    CAT_BOOTS,
    CAT_SANDALS,
    CAT_OTHER
} ProductCategory;

typedef enum {
    GENDER_LADIES,
    GENDER_GENTS,
    GENDER_KIDS,
    GENDER_UNISEX
} ProductGender;

typedef struct Measurement {
    char size[10];       // "S", "M", "L", etc.
    float length;
    float chest;
    float waist;
} Measurement;

typedef struct Product {
    int id;
    char* name;
    ProductCategory category;
    ProductGender gender;
    float price;
    int stock;
    Measurement measurements;
    int hasMeasurements;
    struct Product *left, *right;
} Product;

Product* addProduct(Product* root, int id, const char* name, ProductCategory category,
                   ProductGender gender, float price, int stock, const Measurement* measurements);
void displayProducts(Product* root);
Product* searchProduct(Product* root, int id);
const char* categoryToString(ProductCategory cat);
const char* genderToString(ProductGender gender);

#endif

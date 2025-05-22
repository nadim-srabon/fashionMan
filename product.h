#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_FABRIC_LENGTH 50

typedef enum {
    CAT_SHIRT,
    CAT_KURTA,
    CAT_PONGA_BLAZER,
    CAT_SHERWANI,
    CAT_PANT,
    CAT_KAMEEZ,
    CAT_ANANDALI,
    CAT_CROWN,
    CAT_KURDI,
    CAT_PAIGMA,
    CAT_OTHER
} ProductCategory;

typedef enum {
    GENDER_LADIES,
    GENDER_GENTS,
    GENDER_KIDS,
    GENDER_UNISEX
} ProductGender;

// Fabric types from your images
typedef enum {
    FAB_BAKSI_PRIMIT_160,
    FAB_ORBINDO_PRIMIT_150,
    FAB_JORGET_200,
    FAB_RAYMOND_COTTON_800,
    FAB_GRINGA_1000,
    FAB_ORBINDO_700,
    FAB_OTHER
} FabricType;

typedef struct Measurement {
    char size[10];
    union {
        struct {
            float length;
            float chest;
            float waist;
        };
        struct {
            float k_length;
            float k_shoulder_width;
            float k_sleeve_length;
            float k_neckline;
            float k_armhole;
        };
        struct {
            float s_neck_circumference;
            float s_chest;
            float s_shoulder_width;
            float s_sleeve_length;
            float s_waist_circumference;
            float s_shirt_length;
            float s_cuff_circumference;
        };
    };
} Measurement;

typedef struct Product {
    int id;
    char* name;
    ProductCategory category;
    ProductGender gender;
    float price;
    int stock;
    FabricType fabric;
    Measurement measurements;
    int hasMeasurements;
    struct Product *left, *right;
} Product;

const char* fabricToString(FabricType fabric);
Product* addProduct(Product* root, int id, const char* name, ProductCategory category,
                   ProductGender gender, float price, int stock, FabricType fabric,
                   const Measurement* measurements);
void displayProducts(Product* root);
Product* searchProduct(Product* root, int id);
const char* categoryToString(ProductCategory cat);
const char* genderToString(ProductGender gender);

#endif

#include <stdio.h>

#define MAX 100
static int wishlist[MAX];
static int top = -1;

void pushWishlist(int productId) {
    if (top == MAX - 1) {
        printf("Wishlist full.\n");
        return;
    }
    wishlist[++top] = productId;
    printf("Product %d added to wishlist.\n", productId);
}

void viewWishlist(void) {
    if (top == -1) {
        printf("Wishlist is empty.\n");
        return;
    }
    printf("Wishlist (top to bottom):\n");
    for (int i = top; i >= 0; i--)
        printf("Product ID: %d\n", wishlist[i]);
}

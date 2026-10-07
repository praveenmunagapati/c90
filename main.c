#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char model[20];
    double price;
} Laptop;

int main() {
    Laptop inventory[2] = {
        {101, "ThinkPad", 85000.50},
        {102, "MacBook", 120000.00}
    };

    // 1. Open binary file for writing ("wb")
    FILE *file_out = fopen("inventory.bin", "wb");
    if (!file_out) return 1;

    // Write the entire array block of 2 structures at once
    fwrite(inventory, sizeof(Laptop), 2, file_out);
    fclose(file_out);

    // 2. Open binary file for reading ("rb")
    FILE *file_in = fopen("inventory.bin", "rb");
    if (!file_in) return 1;

    Laptop imported_item;
    printf("--- Reading Binary Structs ---\n");
    // Read structured blocks one-by-one
    while (fread(&imported_item, sizeof(Laptop), 1, file_in) == 1) {
        printf("ID: %d | Model: %s | Price: %.2f\n",
               imported_item.id, imported_item.model, imported_item.price);
    }

    fclose(file_in);
    return 0;
}

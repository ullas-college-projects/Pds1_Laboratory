#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_SIZE (50 + 1)
#define MAX_NUMBER_OF_BRANDS (8)
#define NUMBER_OF_FIELDS (6)
#define NUMBER_OF_PRODUCTS (8)

typedef struct {
    char name[STRING_SIZE];
    char brand[STRING_SIZE];
    float price;
} product_t;

typedef struct {
    char name[STRING_SIZE];
    float sum_of_products_prices;
    int number_of_products;
} brand_t;

product_t parse_product(char* data) {
    char strings[NUMBER_OF_FIELDS][STRING_SIZE];
    
    int begin = 0;
    int count = 0;
    for (int i = 0; i < strlen(data); ++i) {
        if (data[i] == ' ' || data[i] == '\n') {
            int j;
            for (j = begin; j < i; ++j) {
                strings[count][j - begin] = data[j];
            }
            int index = j - begin;
            strings[count][index] = '\0';
            begin = i + 1;
            count++;
        } 
    }
    
    product_t product;
    strcpy(product.name, strings[0]);
    strcpy(product.brand, strings[1]);
    product.price = atof(strings[2]);
    
    return product;
}

int main() {
    product_t products[NUMBER_OF_PRODUCTS];
    brand_t brands[MAX_NUMBER_OF_BRANDS];
    
    
    int count = 0;
    for (int i = 0; i < NUMBER_OF_PRODUCTS; ++i) {
        char data[3 * STRING_SIZE];
        fgets(data, 3 * STRING_SIZE, stdin); 
        product_t product = parse_product(data);

        int find = 0;
        for (int j = 0; j < MAX_NUMBER_OF_BRANDS; ++j) {
            if (strcmp(brands[j].name, product.brand) == 0) {
                brands[j].sum_of_products_prices += product.price;
                find = 1;
                brands[j].number_of_products++;
            } 
        }

        if (!find) {
            strcpy(brands[count].name, product.brand);
            brands[count].sum_of_products_prices = product.price;
            brands[count].number_of_products = 1;
            count++;
        }
    }

    float sum_of_prices = 0.0f;
    int total_number_of_products = 0;
    for (int i = 0; i < count; ++i) {
        printf("%s %d\n", brands[i].name, brands[i].number_of_products);
        sum_of_prices += brands[i].sum_of_products_prices;
        total_number_of_products += brands[i].number_of_products;
    }

    printf("media total %.2f\n", sum_of_prices / (float) total_number_of_products);

    for (int i = 0; i < count; ++i) {
        printf("media %s %.2f\n", brands[i].name, brands[i].sum_of_products_prices / (float) brands[i].number_of_products);
    }
    
    return 0;
}
#include <stdio.h>

int main(int argc, char** argv) {
    float celsius_temperature;
    scanf("%f", &celsius_temperature);

    float farenheit_temperature = 1.8 * celsius_temperature + 32;

    printf("%.0f", farenheit_temperature);

    return 0;
}
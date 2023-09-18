#include <stdio.h>

int main() {
    double pi = 3.141592653589793238462643383279502884L;
    double aimed_difference;
    scanf("%lf", &aimed_difference);

    int term_number = 1;
    double pi_from_leibniz_series = 4;
    double even_number = 3.0;
    double difference = pi_from_leibniz_series - pi;
    
    while(difference >= aimed_difference) {
        term_number++;
        if (term_number % 2 == 0) pi_from_leibniz_series -= 4.0 / even_number;
        else pi_from_leibniz_series += 4.0 / even_number;
        even_number += 2;
        if (term_number % 2 != 0) difference = pi_from_leibniz_series - pi;
    }

    printf("%d", term_number - 1);

    return 0;
}
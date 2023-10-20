#include <stdio.h>

int is_prime(unsigned long long num) {
    if (num < 2) return -1;
    for (int i = 2; num >= i * i; ++i) {
        if(num % i == 0) return 0;
    }
    
    return 1;
}

unsigned long long sum_of_primes(unsigned long long num) {
    unsigned long long counter = 2;
    unsigned long long num_of_primes = 0;
    unsigned long long sum_of_primes = 0;
    while(1) {
        if (num_of_primes == num) {
            break;
        }
        
        if(is_prime(counter)) {
            num_of_primes++; 
            sum_of_primes += counter;
        }
        
        counter++;
    }
    
    return sum_of_primes;
}

int main() {
    unsigned long long num;
    while(scanf("%llu", &num) != EOF) {
        printf("%llu\n", sum_of_primes(num));
    }
    
    return 0;
}
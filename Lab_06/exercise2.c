#include <stdio.h>

int is_prime(unsigned long long num) {
    if (num < 2) return -1;
    for (int i = 2; i < num; ++i) {
        if(num % i == 0) return 0;
    }
    
    return 1;
}

int main() {
    unsigned long long num;
    while(scanf("%llu", &num) != EOF) {
        printf("%d\n", is_prime(num));
    }
    
    return 0;
}
#include <stdio.h>

int is_prime(int x) {
    for (int i = 2; i < x; ++i) {
       if(x % i == 0) {
           return 0;
       }  
    }
    
    return 1;
}


int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    for (int i = x + 1; i < y; ++i) {
        if(is_prime(i)) {
           printf("%d\n", i);
        } 
    }
}
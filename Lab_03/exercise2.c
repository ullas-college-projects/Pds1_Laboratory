#include <stdio.h>

#define MAX_NUMBER (801)

int fib_of(int number, int* fib_table) {
    if(fib_table[number] != -1) {
        return fib_table[number]; 
    }

    return fib_of(number - 1, fib_table) + fib_of(number - 2, fib_table);
}

int main() {
    int fib_table[MAX_NUMBER];
    for (int i = 0; i < MAX_NUMBER; ++i) {
        fib_table[i] = -1; 
    }
    
    fib_table[0] = 0;
    fib_table[1] = 1;
    
    while(1) {
        int number;
        scanf("%d", &number);
        if(number < 0 | number > 800) break;
        int fibonnaci_value = fib_of(number, &fib_table[0]);
        printf("%d\n", fibonnaci_value);
    }
    
    return 0;
}
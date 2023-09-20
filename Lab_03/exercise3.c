#include <stdio.h>

#define SIZE (10)

int main() {
    int array[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &array[i]); 
    }

    for (int i = SIZE - 1; i >= 0; --i) {
        printf("%d\n", array[i]); 
    }
    
    return 0;
}
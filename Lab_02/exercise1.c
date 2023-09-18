#include <stdio.h>

int main() {
    int n, x0, x1;
    scanf("%d", &n);
    scanf("%d", &x0);
    scanf("%d", &x1);

    printf("X0: %d\n", x0);
    printf("X1: %d\n", x1);
    
    // X(n - 1)
    int first_term = x1;
    // X(n - 2)
    int second_term = x0;

    // X(n) = 4 * X(n-1) - X(n-2)
    for (int i = 2; i <= n; ++i) {
       int value = 4 * first_term - 2 * second_term;  
       second_term = first_term;
       first_term = value;
       printf("X%d: %d\n", i, value);
    }
   
    return 0;
}

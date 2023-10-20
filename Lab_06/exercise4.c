#include <stdio.h>

int is_bissext(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    }
    
    if (year % 400 == 0) {
        return 1;
    } 
    
    return 0;
}

int main() {
    int year;
    while (scanf("%d", &year) != EOF) {
        printf("%d\n", is_bissext(year));
    }
    
    return 0;
}
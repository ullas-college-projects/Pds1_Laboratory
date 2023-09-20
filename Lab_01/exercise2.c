#include <stdio.h>

int main(int argc, char** argv) {
    int x, y, z;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    int biggest = x;
    
    if(y > x) {
        biggest = y;
    }
    
    if(z > biggest) {
        biggest = z;
    }
    
    printf("%d", biggest);

    return 0;
}
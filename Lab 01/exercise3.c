#include <stdio.h>

int main(int argc, char** argv) {
    int x, y, z;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    if(x % y == 0 && x % z == 0) {
        printf("O número é divisível");
    }

    else printf("O número não é divisível");

    return 0;
}
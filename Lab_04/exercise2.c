#include <stdio.h>
#include <string.h>

#define STRING_SIZE (100 + 1)

int main() {
    char str[STRING_SIZE];
    char reversed[STRING_SIZE];

    fgets(str, STRING_SIZE, stdin);

    int length = strlen(str);

    for (int i = length - 2; i >= 0; --i) {
        reversed[length - i - 2] = str[i]; 
    }
    
    reversed[length - 1] = '\0';

    puts(reversed);

    return 0;
}
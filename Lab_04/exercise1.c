#include <stdio.h>
#include <string.h>

#define STRING_SIZE (100 + 1)

int main() {
    char str1[STRING_SIZE];
    char str2[STRING_SIZE];

    fgets(str1, STRING_SIZE, stdin);
    fgets(str2, STRING_SIZE, stdin);
    
    str1[strlen(str1) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';
    
    strcat(str1, str2);

    puts(str1);

    return 0;
}
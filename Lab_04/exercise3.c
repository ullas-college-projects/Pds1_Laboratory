#include <stdio.h>
#include <string.h>

#define STRING_SIZE (100 + 1)

int main() {
    char str[STRING_SIZE];
    char c1[3], c2[3];
    
    fgets(str, STRING_SIZE, stdin);
    setbuf(stdin, NULL);
    fgets(c1, 3, stdin);
    fgets(c2, 3, stdin);
    
    for (int i = 0; i < strlen(str) - 1; ++i) {
        if(str[i] == c1[0]) {
           str[i] = c2[0]; 
           break;
        } 
    }

    puts(str); 
    
    return 0;
}
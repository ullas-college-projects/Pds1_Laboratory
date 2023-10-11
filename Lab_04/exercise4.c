#include <stdio.h>
#include <string.h>

#define STRING_SIZE (100 + 1)

int is_substring(char* str, char* sub_str) {
   if (strlen(str) < strlen(sub_str)) return 0;

    for (int i = 0; i < strlen(str) - 1; ++i) {
        int is_sub = 1; 
        for (int j = 0; j < strlen(sub_str) - 1; ++j) {
            if(str[i + j] != sub_str[j]) {
                is_sub = 0;
            }     
        }                  
        
        if (is_sub == 1) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char str[STRING_SIZE];
    char sub_str[STRING_SIZE];

    fgets(str, STRING_SIZE, stdin);
    fgets(sub_str, STRING_SIZE, stdin);

    if(is_substring(str, sub_str)) {
        printf("É substring");
    } 
    else {
        printf("Não é substring");
    }

    
    return 0;
}
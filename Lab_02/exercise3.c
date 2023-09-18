#include <stdio.h>

int main() {
    for (int i = 0; i < (457 - 233); i++) {
        int current_number = i + 233;
        if (current_number > 300 && current_number < 400) {
            if (i % 3 == 0) printf("%d\n", current_number + 1);
        } 
        
        else {
            if (i % 5 == 0) {
                if (current_number > 400) printf("%d\n", current_number - 1);
                else printf("%d\n", current_number);
            }
        }
    }

    printf("457");
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number_of_rows, number_of_columns;
    scanf("%d", &number_of_rows);
    scanf("%d", &number_of_columns);
    
    int** matrix = (int**) calloc(number_of_rows, sizeof (int));
    for (int i = 0; i < number_of_rows; ++i) {
        matrix[i] = (int*) calloc(number_of_columns, sizeof (int));
    }

    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            scanf("%d", &matrix[i][j]); 
        }
    }
    
    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            printf("%d ", -matrix[i][j]); 
        }
        printf("\n");
    }

    return 0;
}
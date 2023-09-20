#include <stdio.h>
#include <stdlib.h>

int contains(int* array, int size, int number) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == number) return 1; 
    } 
    
    return 0;
}

int main() {
    int number_of_aeds_students;
    scanf("%d //número de alunos em AEDS 1", &number_of_aeds_students);
    int* aeds_students_ids = (int*) calloc(number_of_aeds_students, sizeof (int));
    for (int i = 0; i < number_of_aeds_students; ++i) {
        scanf("%d", &aeds_students_ids[i]); 
    }

    int number_of_calculus_students;
    scanf("%d //número de alunos em Cálculo 1", &number_of_calculus_students);
    int* calculus_students_ids = (int*) calloc(number_of_calculus_students, sizeof (int));
    for (int i = 0; i < number_of_calculus_students; ++i) {
        scanf("%d", &calculus_students_ids[i]);
    }

    for (int i = 0; i < number_of_aeds_students; ++i) {
        if (contains(calculus_students_ids, number_of_calculus_students, aeds_students_ids[i])) {
            printf("%d\n", aeds_students_ids[i]);
        } 
    } 
    
    return 0;
}
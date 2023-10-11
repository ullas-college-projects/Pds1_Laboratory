#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_SIZE (50 + 1)
#define NUMBER_OF_PERSONS (4)


typedef struct {
    char name[STRING_SIZE];
    unsigned int age;
    float wage;
} person;

person parse_person(char* data) {
    person new_person;
    int count = 0;
    int space_indexes[2];
    
    for (int i = 0; i < strlen(data) - 1; ++i) {
        if (data[i] == ' ') {
            space_indexes[count] = i;
            count++;
        } 
    }

    char name[STRING_SIZE];
    for (int i = 0; i < space_indexes[0]; ++i) {
        name[i] = data[i];
        if (i == space_indexes[0] - 1) name[i + 1] = '\0';
    }

    char age_str[STRING_SIZE];
    for (int i = space_indexes[0] + 1; i < space_indexes[1]; ++i) {
        age_str[i - (space_indexes[0] + 1)] = data[i];
        if (i == space_indexes[1] - 1) age_str[i - (space_indexes[0] + 1) + 1] = '\0';
    }
    
    char wage_str[STRING_SIZE];
    for (int i = space_indexes[1] + 1; i < strlen(data) - 1; ++i) {
        wage_str[i - (space_indexes[1] + 1)] = data[i];
        if (i == strlen(data) - 2) wage_str[i - (space_indexes[1] + 1) + 1] = '\0';
    }

    strcpy(new_person.name, name);
    new_person.age = (unsigned int) atoi(age_str);
    new_person.wage = atof(wage_str);
    
    return new_person;
}

int main() {
    person array[NUMBER_OF_PERSONS];
    char operation[STRING_SIZE];
    
    int count = 0;
    while (fgets(operation, STRING_SIZE, stdin)) {
        if (strcmp(operation, "inserir\n") == 0) {
            char data[2 * STRING_SIZE];
            fgets(data, 2 * STRING_SIZE, stdin);
            if (count == 4) {
                printf("Espaco insuficiente\n");
                continue;
            }
            person new_person = parse_person(data);
            array[count] = new_person;
            printf("Registro %s %d %.2f inserido\n", new_person.name, new_person.age, new_person.wage);
            count++;
        } 
        
        else if (strcmp(operation, "mostrar\n") == 0){
            char searched_person[STRING_SIZE];
            fgets(searched_person, STRING_SIZE, stdin);
            searched_person[strlen(searched_person) - 1] = '\0'; 
            
            int found = 0;
            for (int i = 0; i < count; ++i) {
                if (strcmp(searched_person, array[i].name) == 0) {
                    printf("Registro %s %d %.2f\n", array[i].name, array[i].age, array[i].wage);
                    found = 1;
                } 
            }

            if (!found) {
                printf("Registro ausente\n");
            }
        }
    }
    
    return 0;
}
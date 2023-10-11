#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_SIZE (50 + 1)
#define NUMBER_OF_PERSONS (5)
#define NUMBER_OF_FIELDS (6)

typedef struct {
    char street[STRING_SIZE];
    unsigned int number;
    char state[STRING_SIZE];
} address_t;

typedef struct {
    char name[STRING_SIZE];
    unsigned int age;
    float wage;
    address_t address; 
} person_t;

person_t parse_person(char* data) {
    person_t new_person;
    char strings[NUMBER_OF_FIELDS][STRING_SIZE];
    
    int begin = 0;
    int count = 0;
    for (int i = 0; i < strlen(data); ++i) {
        if (data[i] == ' ' || data[i] == '\n') {
            int j;
            for (j = begin; j < i; ++j) {
                strings[count][j - begin] = data[j];
            }
            int index = j - begin;
            strings[count][index] = '\0';
            begin = i + 1;
            count++;
        } 
    }
    
    address_t address;
    strcpy(address.street, strings[3]);
    address.number = (unsigned int) atoi(strings[4]);
    strcpy(address.state, strings[5]);
    
    person_t person;
    strcpy(person.name, strings[0]);
    person.age = (unsigned int) atoi(strings[1]);
    person.wage = atof(strings[2]);
    person.address = address;
    
    return person;
}

int main() {
    person_t array[NUMBER_OF_PERSONS];
    char operation[STRING_SIZE];
    
    int count = 0;
    while (fgets(operation, STRING_SIZE, stdin)) {
        if (strcmp(operation, "inserir\n") == 0) {
            char data[2 * STRING_SIZE];
            fgets(data, 2 * STRING_SIZE, stdin);
            if (count == NUMBER_OF_PERSONS) {
                printf("Espaco insuficiente\n");
                continue;
            }
            person_t new_person = parse_person(data);
            array[count] = new_person;
            printf("Registro %s %d %.2f %s %d %s inserido\n", new_person.name, new_person.age, new_person.wage, new_person.address.street, new_person.address.number, new_person.address.state);
            count++;
        } 
        
        else if (strcmp(operation, "alterar\n") == 0) {
            char data[4 * STRING_SIZE];
            fgets(data, 2 * STRING_SIZE, stdin);
            person_t person_to_alter = parse_person(data);

            int index = -1;
            for (int i = 0; i < count; ++i) {
                if (strcmp(person_to_alter.name, array[i].name) == 0) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                printf("Registro ausente para alteracao\n");
                continue;
            }           
            
            array[index] = person_to_alter;
            printf("Registro %s %d %.2f %s %d %s alterado\n", person_to_alter.name, person_to_alter.age, person_to_alter.wage, person_to_alter.address.street, person_to_alter.address.number, person_to_alter.address.state);
        }
        
        else if (strcmp(operation, "mostrar\n") == 0){
            char searched_person[STRING_SIZE];
            fgets(searched_person, STRING_SIZE, stdin);
            searched_person[strlen(searched_person) - 1] = '\0'; 
            
            int found = 0;
            for (int i = 0; i < count; ++i) {
                if (strcmp(searched_person, array[i].name) == 0) {
                    printf("Registro %s %d %.2f %s %d %s\n", array[i].name, array[i].age, array[i].wage, array[i].address.street, array[i].address.number, array[i].address.state);
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
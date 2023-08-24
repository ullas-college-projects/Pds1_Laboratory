#include <stdio.h>

#define HUNDRED (0)
#define FIFTY (1)
#define TWENTY (2)
#define TEN (3)
#define FIVE (4)
#define TWO (5)
#define ONE (6)

int main(int argc, char** argv) {
    int money_value;
    int number_of_ballots[7] = {0, 0, 0, 0, 0, 0, 0};

    scanf("%d", &money_value);

    while(money_value >= 100) {
        number_of_ballots[HUNDRED] = money_value / 100; 
        money_value = 100;
    } 

    while(money_value >= 50) {
        number_of_ballots[FIFTY] = money_value / 50; 
        money_value -= 50;
    }    

    while(money_value >= 20) {
        number_of_ballots[TWENTY] = money_value / 20; 
        money_value -= 20;
    } 

    while(money_value >=  10) {
        number_of_ballots[TEN] = money_value / 10; 
        money_value -= 10;
    } 

    while(money_value >= 5) {
        number_of_ballots[FIVE] = money_value / 5; 
        money_value -= 5;
    } 

    while(money_value >= 2) {
        number_of_ballots[TWO] = money_value / 2; 
        money_value -= 2;
    } 

    if(money_value == 1) {
        number_of_ballots[ONE] = 1;
    }

    printf("100: %d\n", number_of_ballots[HUNDRED]);
    printf("50: %d\n", number_of_ballots[FIFTY]);
    printf("20: %d\n", number_of_ballots[TWENTY]);
    printf("10: %d\n", number_of_ballots[TEN]);
    printf("5: %d\n", number_of_ballots[FIVE]);
    printf("2: %d\n", number_of_ballots[TWO]);
    printf("1: %d\n", number_of_ballots[ONE]);
    

    return 0;
}


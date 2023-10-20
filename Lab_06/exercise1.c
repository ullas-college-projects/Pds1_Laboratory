#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day; 
    int month;
    int year;
} date_t;

#define FEBRUARY (2)
#define NUMBER_OF_MONTHS (12)

int number_of_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_bissext(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    }
    
    if (year % 400 == 0) {
        return 1;
    } 
    
    return 0;
}

int difference_in_days(date_t begin, date_t end) {
    int counter_year = begin.year;
    int amount_of_days = number_of_days[begin.month] - begin.day;
    if (begin.month == FEBRUARY && is_bissext(begin.year)) amount_of_days = number_of_days[begin.month] + 1 - begin.day;
    int counter_month = begin.month + 1;
    
    while(counter_year < end.year) {
        while(counter_month <= NUMBER_OF_MONTHS) {
            if (counter_month == FEBRUARY) {
                if (is_bissext(counter_year)) {
                    amount_of_days += number_of_days[FEBRUARY] + 1 ;
                    counter_month++;
                    continue;        
                }  
            }
            
            amount_of_days += number_of_days[counter_month];
            counter_month++;
        }
        counter_year++;
        counter_month = 1;
    }

    while(counter_month < end.month) {
        if (counter_month == FEBRUARY) {
            if (is_bissext(end.year)) {
                amount_of_days += number_of_days[FEBRUARY] + 1 ;
                counter_month++;
                continue;
            }
        }

        amount_of_days += number_of_days[counter_month];
        counter_month++;
    }

    amount_of_days += end.day;
    
    return amount_of_days + 1;
}

int main() {
    date_t date;
    date_t start_date = {17, 9, 2020};

    while (scanf("%d %d %d", &date.day, &date.month, &date.year) != EOF) {
        int res = difference_in_days(date, start_date);
        printf("%d\n", res);
        setbuf(stdin, NULL);
    }
    
    return 0;
}
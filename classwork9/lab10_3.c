#include <stdio.h>
#include <stdbool.h>

struct Date {
    int day;
    int month;
    int year;
};

bool is_leap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int days_in_month(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return is_leap(year) ? 29 : 28;
        default:
            return 0; 
    }
}

void print_day(struct Date d) {
    printf("%02d.%02d.%04d\n", d.day, d.month, d.year);
}

void input_Date(struct Date *d) {
    printf("Input date (dd.mm.yyyy): ");
    scanf("%d.%d.%d", &d->day, &d->month, &d->year);
}

struct Date next_day(struct Date d) {
    d.day++;
    if(d.day > days_in_month(d.month, d.year)) {
        d.day = 1;
        d.month++;
        if(d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

int day_of_week(struct Date d) {
    int y = d.year;
    int m = d.month;
    if(m < 3) {
        m += 12;
        y -= 1;
    }
    int K = y % 100;
    int J = y / 100;
    int f = d.day + 13*(m + 1)/5 + K + K/4 + J/4 + 5*J;
    return f % 7;
}

void print_weekday(int w) {
    const char* days[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    printf("%s\n", days[w]);
}

int main() {
    struct Date today, tomorrow;

    input_Date(&today);

    printf("Today: ");
    print_day(today);

    tomorrow = next_day(today);
    printf("Tomorrow: ");
    print_day(tomorrow);

    printf("Day of week: ");
    print_weekday(day_of_week(today));

    return 0;
}
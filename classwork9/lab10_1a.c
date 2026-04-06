#include <stdio.h>
#include <stdbool.h>

struct Date{
    int day;
    int month;
    int year;
};
void print_day(struct Date x){
    printf("%02d.%02d.%04d\n", x.day,x.month,x.year);
}
int input_Date(struct Date*x){
    printf("Input date:");
    scanf("%d.%d.%d", &(*x).day, &x->month,&x->year);
    return true;
}
int main(){
    struct Date y;
    input_Date(&y);
    print_day(y);
}

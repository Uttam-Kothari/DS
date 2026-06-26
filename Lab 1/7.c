//Convert Days into Year, Week and Days

#include <stdio.h>

void main() {
    int days, year, week, rem;

    printf("Enter days: ");
    scanf("%d", &days);

    year = days / 365;
    rem = days % 365;

    week = rem / 7;
    rem = rem % 7;

    printf("%d Year %d Week %d Day", year, week, rem);

}
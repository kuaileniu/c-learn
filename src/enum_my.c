#include <stdio.h>

enum Weekday {
    MONDAY = 1,
    TUESDAY=9,
    WEDNESDAY=10,
    THURSDAY=11,
    FRIDAY=12,
    SATURDAY=13,
    SUNDAY=14
};

void show_enum(void) {
    enum Weekday today = WEDNESDAY;

    printf("Monday: %d\n", MONDAY);
    printf("Tuesday: %d\n", TUESDAY);
    printf("Wednesday: %d\n", WEDNESDAY);
    printf("Thursday: %d\n", THURSDAY);
    printf("Friday: %d\n", FRIDAY);
    printf("Saturday: %d\n", SATURDAY);
    printf("Sunday: %d\n", SUNDAY);
}
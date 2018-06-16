#include <stdio.h>
#include <stdlib.h>

struct date{
    int month;
    int day;
    int year;
};

int main()
{

    struct date today;
    today.month=06;
    today.day=05;
    today.year=2018;

    struct date tomorrow = {06,06,2018};

    struct date yesterday = {.year=2018,.month=06,.day=04};

    struct date *pDate = &today;

    printf("%p\n",pDate);


    printf("yesterday's date is %i-%i-%i.\n",
        yesterday.year,yesterday.month,yesterday.day);

    printf("Today's date is %i-%i-%i.\n",
           today.year,today.month,today.day);

    printf("Tomorrow's date is %i-%i-%i.\n",
           tomorrow.year,tomorrow.month,tomorrow.day);

    return 0;
}



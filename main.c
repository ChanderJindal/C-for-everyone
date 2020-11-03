#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum month{January,February,March,April,May,June,July,August,September,October,November,December};
// 0 ,2,4,6,7,9,11
//jan, march,may,july,aug,oct,dec
void months(int n){ //  this finds and detects the Current Month with respect to enum Month and prints it
    n %= 12; // %12 so, if it goes from Dec. to Jan without error
switch(n){ // switch sure needs break statement but is faster than if else
    case(0): printf("January ");
    break;
    case(1): printf("February ");
    break;
    case(2): printf("March ");
    break;
    case(3): printf("April ");
    break;
    case(4): printf("May ");
    break;
    case(5): printf("June ");
    break;
    case(6): printf("July ");
    break;
    case(7): printf("August ");
    break;
    case(8): printf("September ");
    break;
    case(9): printf("October ");
    break;
    case(10): printf("November ");
    break;
    case(11): printf("December ");
    break;
}
}

struct date{ // the general structure
int day;
int month;
};

void next_date(struct date str){ // this is the main next date function
    printf("For %d ", str.day) ; months(str.month); printf("The Next Date is "); // it places the current date using above function
if((str.month%2 == 0 && str.month < 7) || (str.month%2 ==1 && str.month > 6)){ // a bit creative way of finding months with 31 days
    if(str.day < 30){// general condition
        str.day ++;
    }else{ // condition for last day of month
    str.month++;
    str.day  = 1;
    }
}else{
if(str.day <29){// general condition
    str.day ++;
}else{// condition for last day of month
str.day ++;
str.month++;
}
}
if(str.month == 1 && str.day  > 28){ // in the above conditions Feb. was not paid any attention, so for that here is the safety Net
    str.month = 2; str.day  = 1; // only possible scenario
}
months(str.month); // printing answer month first
printf("%d \n", str.day ); // date second

}

void input(int new_day , int new_month, struct date str){ // this function takes in the date and the data structure
str.day = new_day;
str.month = new_month-1; // I am taking DD/MM  type date starting with 0 so, month is new_month -1
next_date(str); // it triggers the function above for next date
printf("\n");
}


int main(){
// February 28, March 14, October 31, and  December 31.
printf("Test Cases \n\n");

struct date d1;// one struct date is enough, it's re-used
input(28,2,d1); // It triggers the initial function
input(14,3,d1);
input(31,10,d1);
input(31,12,d1);

    return 0;
}

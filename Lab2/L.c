#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  /*state all variables used in code*/
  int yyyy;
  int mm;
  int dd;
  int num;
  int numDays;
  int totalDays, dummy;
  int yyyyOutput = 0;
  int mmOutput = 0;
  int ddOutput = 0;
  int dayOfYear[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
  int dayOfLeapYear[12] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};
  int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  /*check if user gives enough information*/
  if (argc < 5) {
    printf("invalid date\n");
    exit(0);
  }
  else{
    dd = atoi ( argv[1] );
    mm = atoi ( argv[2] );
    yyyy = atoi ( argv[3] );
    num = atoi ( argv[4] );
  }

  /*check to see if number of days is less than or equal to 300, otherwise exit program*/
  if (num > 300) {
    printf("invalid number of days\n");
    exit(0);
  }
  if ((mm < 1)||(mm > 12)) {
    printf("Error month must fall between (1-12)\n");
    exit(0);
  }
  else if((dd > monthLength[mm - 1])||(dd < 1)){
    printf("day must fall in (1 - %d)\n", monthLength[mm-1]);
    exit(0);
  }



  /*check to see if yyyy is a leap year or not and calculate totaldays*/
  if((0 == (yyyy % 4)) && ((yyyy % 100) != 0) || ((yyyy % 400) == 0)){
    monthLength[1] = 29;
    numDays = dayOfLeapYear[mm-1] + dd;
    totalDays = numDays + num;
    dummy = totalDays;
  }
  else{
    numDays = dayOfYear[mm-1] + dd;
    totalDays = numDays + num;
    dummy = totalDays;
  }


  /*if number inputted and day or year of date inputted is greater than 366 or 365
  (depending on if its a leap year or not) follow equation. otherwise keep output
  year date same as inputted one*/
  if (monthLength[1] == 29) {
    if (totalDays > 366) {
      yyyyOutput = yyyy + 1;
      totalDays = totalDays - 366;
    }
    else{
      yyyyOutput = yyyy;
    }
  }
  else{
    if (totalDays > 365) {
      yyyyOutput = yyyy + 1;
      totalDays = totalDays - 365;
    }
    else{
      yyyyOutput = yyyy;
    }
  }


  /*this calculates the month ouput*/
  int true = 0;
  mmOutput = -1;
  if (monthLength[1] == 29) {
    while (true == 0) {
        mmOutput++;
        if ((totalDays - dayOfLeapYear[mmOutput]) < 0) {
          true = 1;
          mmOutput = mmOutput -1;
        }
      }
  }
  else{
    while (true == 0) {
        mmOutput++;
        if ((totalDays - dayOfYear[mmOutput]) < 0) {
          true = 1;
          mmOutput = mmOutput -1;
        }
      }
  }


  if (monthLength[1] == 29) {
    ddOutput = totalDays - dayOfLeapYear[mmOutput] ;
  }
  else{
    ddOutput = totalDays - dayOfYear[mmOutput];
  }

  if (((0 == (yyyy % 4)) && ((yyyy % 100) != 0) || ((yyyy % 400) == 0)) && ((dummy - 366) > dayOfLeapYear[1])) {
    ddOutput++;
  }

  mmOutput++;

  printf("%d %d %d\n", ddOutput, mmOutput, yyyyOutput);

  return 0;
}

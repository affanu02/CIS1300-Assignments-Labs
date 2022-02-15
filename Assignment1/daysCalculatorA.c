#include <stdio.h>
#include <stdlib.h>

/*
 *   Program name: daysCalculatorA
 *   Author: Affan Khan
 *   Last Update: September 27, 2019
 *   Function: to print out number of days between two dates given on command line
 *   Compilation: gcc -ansi -o daysCalculatorA daysCalculatorA.c
 *   Execution: ./daysCalculatorA 2 4 2001 4 2 2001
 */

int main(int argc, char *argv[]) {

  /*declare variables and arrays needed*/
  int dayOfYear[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
  int dayOfLeapYear[12] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};
  int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dd1 = 0;
  int mm1 = 0;
  int yyyy1 = 0;
  int dd2 = 0;
  int mm2 = 0;
  int yyyy2 = 0;
  int startDay, endDay, numDays;


  /*check if user gives enough information*/
  if (argc < 7) {
    printf("Usage: ./A dd1 mm1 yyyy1 dd2 mm2 yyyy2\n");
  }
  else{
    dd1 = atoi ( argv[1] );
    mm1 = atoi ( argv[2] );
    yyyy1 = atoi ( argv[3] );
    dd2 = atoi ( argv[4] );
    mm2 = atoi ( argv[5] );
    yyyy2 = atoi ( argv[6] );
  }


  /*check to see if its a leap year, base off calcuations if it is or not*/
  if((0 == (yyyy1 % 4)) && ((yyyy1 % 100) != 0) || ((yyyy1 % 400) == 0)){
    monthLength[1] = 29;
    startDay = dayOfLeapYear[mm1 - 1] + dd1;
    endDay = dayOfLeapYear[mm2 - 1] + dd2;
    numDays = endDay - startDay;
  }
  else{
    startDay = dayOfYear[mm1 - 1] + dd1;
    endDay = dayOfYear[mm2 - 1] + dd2;
    numDays = endDay - startDay;
  }


  /*check if user gives proper info for required calculations. Otherwise
  print out number of days between dates*/
  if ((mm1 < 1)||(mm1 > 12)) {
    printf("Error month must fall between (1-12)\n");
  }
  else if ((mm2 < 1)||(mm2 > 12)) {
    printf("Error month must fall between (1-12)\n");
  }
  else if((dd1 > monthLength[mm1 - 1])||(dd1 < 1)){
    printf("day must fall in (1 - %d)\n", monthLength[mm1-1]);
  }
  else if((dd2 > monthLength[mm2 - 1])||(dd2 < 1)){
    printf("day must fall in (1 - %d)\n", monthLength[mm2-1]);
  }
  else{
    printf("%d\n", numDays);
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

/*
 *   Program name: daysCalculatorC
 *   Author: Affan Khan
 *   Last Update: September 27, 2019
 *   Function: to print out number of days between two dates given on command
 *   line depending on including the last date or not. the dates given on
 *   command line are in strings.
 *   Compilation: gcc -ansi -o daysCalculatorC daysCalculatorC.c
 *   Execution: ./daysCalculatorC 02-04-2001 03-12-2001 include
 */

int main(int argc, char  *argv[]) {

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
    char * word, *start[11], *end[11];
    int startDay, endDay, numDays;
    char dayS[3];
    char monthS[3];
    char yearS[5];
    char dayE[3];
    char monthE[3];
    char yearE[5];
    /*E = ended date , S = start date*/

    /*got this from the slides*/
    dayS[0] = argv[1][0];
    dayS[1] = argv[1][1];
    dayS[2] = '\0';
    monthS[0] = argv[1][3];
    monthS[1] = argv[1][4];
    monthS[2] = '\0';
    yearS[0] = argv[1][6];
    yearS[1] = argv[1][7];
    yearS[2] = argv[1][8];
    yearS[3] = argv[1][9];
    yearS[4] = '\0';
    dayE[0] = argv[2][0];
    dayE[1] = argv[2][1];
    dayE[2] = '\0';
    monthE[0] = argv[2][3];
    monthE[1] = argv[2][4];
    monthE[2] = '\0';
    yearE[0] = argv[2][6];
    yearE[1] = argv[2][7];
    yearE[2] = argv[2][8];
    yearE[3] = argv[2][9];
    yearE[4] = '\0';

    /*check if user gives enough info and correct info needed*/
    if (argc < 3) {
      printf("Usage: ./A dd-mm-yyyy dd-mm-yyyy char\n");
    }
    else if (argc == 4){
      word = argv[3];
      dd1 = atoi(dayS);
      mm1 = atoi(monthS);
      yyyy1 = atoi(yearS);
      dd2 = atoi(dayE);
      mm2 = atoi(monthE);
      yyyy2 = atoi(yearE);
    }
    else{
      dd1 = atoi(dayS);
      mm1 = atoi(monthS);
      yyyy1 = atoi(yearS);
      dd2 = atoi(dayE);
      mm2 = atoi(monthE);
      yyyy2 = atoi(yearE);
    }

    /*check to see if its a leap year*/
    if((0 == (yyyy1 % 4)) && ((yyyy1 % 100) != 0) || ((yyyy1 % 400) == 0)){
      monthLength[1] = 29;
      startDay = dayOfLeapYear[mm1 - 1] + dd1;
      endDay = dayOfLeapYear[mm2 - 1] + dd2;

      /*does calculations based on include or not*/
      if (strncmp("include" , word) == 0){
        numDays = endDay - startDay + 1;
      }
      else{
        numDays = endDay - startDay;
      }
    }
    else{
      startDay = dayOfYear[mm1 - 1] + dd1;
      endDay = dayOfYear[mm2 - 1] + dd2;

      /*does calculations based on include or not*/
      if (strncmp("include" , word) == 0){
        numDays = endDay - startDay + 1;
      }
      else{
        numDays = endDay - startDay;
      }
    }


    /*check if user gives proper info for required calculations. Otherwise
    calculate the number of days difference*/
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
    else if(numDays < 0) {
        printf("Start day must be before end day\n");
    }
    else{
          printf("%d\n", numDays);

    }

  return 0;
}

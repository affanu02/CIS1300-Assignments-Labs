#include <stdio.h>
#include <stdlib.h>

int isLeap (int year){
  if (((0 == (year % 4)) && ((year % 100) != 0)) || ((year % 400) == 0)) {
    return 1;
  }
  else{
    return 0;
  }
}

#include <stdio.h>
#include <stdlib.h>

int isLeap(int year);

int main(int argc, char *argv[]) {

  if (argc == 3) {
    int startYear = atoi(argv[1]);
    int numLeap = atoi(argv[2]);
    int x = 0;

    while (!(x == numLeap)) {
      if (isLeap(startYear) == 1) {
        x++;
        printf("%d\n", startYear);
      }
      startYear++;
    }
  }
  return 0;
}

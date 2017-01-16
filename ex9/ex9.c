#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int i = 0;
  int end = 25;
  if (argc > 1){
    end = atoi(argv[1]);
  }
  while (i < end) {
    if(i % 15 == 0){
      printf("%d - Fizzbuzz!\n", i);
    } else if (i % 5 == 0) {
      printf("%d - Buzz\n", i);
    } else if (i % 3 == 0) {
      printf("%d - Fizz\n", i);
    } else {
      printf("%d\n", i);
    }
    i++;
  }
  return 0;
}

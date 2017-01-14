#include <stdio.h>

/*This excercize is to introduce the gdb debugger*/

// void crash() {
//   char *test = NULL;
//   int i = 0;
//   for(i = 0; i < 100000; i++){
//     printf("%c", test[i]);
//   }
// }

int main (int argc, char *argv[]){
  int age = 10;
  int height = 72;

  printf("I am %d years old", age);
  printf("I am %d inches tall\n", height);

  // crash();

  return 0;
}

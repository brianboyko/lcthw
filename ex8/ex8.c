#include <stdio.h>

// In C there really isn't a Boolean type;.
// Instead, any integer that's 0 is "false";
// Otherwise, it's true.
// Coming from Javascript, you start to see where "truthy"
// and "falsey" values come from...

int main(int argc, char *argv[]){ //argc - argumentCount ? argv - argument values.
  if(argc == 1){ // no triple equals in C.
    printf("You have no arguments.  You suck.\n");
  } else if (argc > 1 && argc < 4) {
    printf("Here's your arguments:\n");
    for(int i = 1; i < argc; i++){
      printf("%s ", argv[i]);
    }
    printf("\n");
  } else {
    printf("You have too many arguments.  You suck.\n");
  }
  return 0;
}

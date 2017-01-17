#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if (argc != 2) {
    printf("Error: You need one and only one argument.\n");
    return 1;
  }

  // argv[1] == the word you put in, [i] is the letter, and strings in C are
  // terminated with '\0'.  In JS, this would be:
  // (let i = 0; i < arguments[1].length; i++);
  for(int i = 0; argv[1][i] != '\0'; i++){
    char letter = argv[1][i];

    switch(letter) {
      case 'a':
      case 'A': //fallthrough
        printf("%d: 'A'\n", i);
        break;
      case 'e':
      case 'E': //fallthrough
        printf("%d: 'E'\n", i);
        break;
      case 'i':
      case 'I': //fallthrough
        printf("%d: 'I'\n", i);
        break;
      case 'o':
      case 'O': //fallthrough
        printf("%d: 'O'\n", i);
        break;
      case 'u':
      case 'U': //fallthrough
        printf("%d: 'U'\n", i);
        break;
      case 'y':
      case 'Y': //fallthrough
        if (i > 2) {
          // it's only sometimes y.
          printf("%d: 'Y'\n", i);
        } else {
          printf("%d: 'Y' (Not a vowel... here)\n", i);
        }
        break;
      default:
        printf("%d: '%c' (Not vowel)\n", i, letter);
    }
  }

  return 0;
}

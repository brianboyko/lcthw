#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message){
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
  exit(1);
}

// a typedef creates a fake type.
// in this case, for a function pointer.

typedef int (*compare_cb)(int a, int b);

/**
 * a classic bubble sort function that uses compare_cb to do the sorting.
 */

int *bubble_sort(int *numbers, int count, compare_cb cmp){
  int temp = 0;
  // C++ requires implicit cast; C will compile fine without it
  // but will have some "dangerous" behavior.
  int *target = (int *)malloc(count * sizeof(int));

  if (!target){
    die("Memory Error");
  }

  memcpy(target, numbers, count * sizeof(int));

  for(int i = 0; i < count; i++){
    for(int j = 0; j < count - 1; j++){
      if(cmp(target[j], target[j+1]) > 0){
        temp = target[j+1];
        target[j+1] = target[j];
        target[j] = temp;
      }
    }
  }
  return target;
}

int sorted_order(int a, int b){
  return a - b;
}

int reverse_order(int a, int b){
  return b - a;
}

int strange_order(int a, int b){
  if(a == 0 || b == 0) {
    return 0;
  } else {
    return a % b;
  }
};

/**
 * used to test that we are sorting things correctly
 * by doing the sort and printing it out
 */
void test_sorting(int *numbers, int count, compare_cb cmp){
  int *sorted = bubble_sort(numbers, count, cmp);
  if(!sorted){
    die("Failed to sort as requested");
  }
  for(int i = 0; i < count; i++){
    printf("%d ", sorted[i]);
  }
  printf("\n");
  free(sorted);
}

int main(int argc, char *argv[]){
  if(argc < 2){
    die("USAGE: ./ex18.exe 4 3 1 5 6");
  }
  int count = argc - 1;
  char **inputs = argv + 1; // not sure, but without the *, this is a pointer to the second argument.
                            // and **double pointer means ???
  int *numbers = (int *)malloc(count * sizeof(int));
  for(int i = 0; i< count; i++){
    numbers[i] = atoi(inputs[i]);
  }

  test_sorting(numbers, count, sorted_order);
  test_sorting(numbers, count, reverse_order);
  test_sorting(numbers, count, strange_order);
}

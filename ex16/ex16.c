#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight){
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name); // what is going on here?
  who->age = age;
  who->height = height;
  who->weight = weight;
  // I think I get it now. We allocate the memory size needed for a
  // person structure, and point who to it. "*who" is the struct, "who" is the pointer;
  // we then assert that who, as a pointer, exists.
  // then we add... for lack of a better word: "subpointers";
  // for name, age, height and weight, so that they point to the appropriate area.

  return who;
  // we've declared that this function (*Person_create()) will return a struct of type "Person";
  // so we can return the entire structure directly.
  // We also have the "Person_create" pointer so that we can pass this function
  // into other functions as an "int" - because you can't pass in a function.
  // This allows for some lambda stuff and callbacks and the like...
}

void Person_destroy(struct Person *who){
  assert(who != NULL);
  // why both?
  free(who->name);
  free(who);
}

void Person_print(struct Person *who){
  // this takes a memory location as a paremter,
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

void Alternative_person_print(struct Person who){
  printf(" Name is: %s \n", who.name);
  printf(" Address is: %p\n", &who.name);
  printf(" Address of Alice.age is: %p\n", &(who.age));
}

int main(int argc, char *argv[]){
  //make two people structures:
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
  struct Person alice;
  alice.name = "Alice";
  alice.age = 1;
  alice.weight = 2;
  alice.height = 3;

  printf("Alice is at memory location: %p :\n", &alice);

  Person_print(&alice);
  printf("This is the alternative print\n");
  Alternative_person_print(alice);

  printf("Joe is at memory location: %p :\n", joe);
  Person_print(joe);

  printf("Frank is at memory location: %p :\n", frank);
  Person_print(frank);


  printf("Make everyone age 20 years\n");

  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  //destroy them both in cleanup.
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char charOne;
  char charTwo;
  char inputString[80];

  printf("Give me a pair like A B: ");
  fgets(inputString, 80, stdin);
  inputString[strlen(inputString)-1] = 0;

  printf("inputString: %s\n", inputString);
  sscanf(inputString, "%c %c" , &charOne, &charTwo);
   printf("charOne: %c\n", charOne);
   printf("charTwo: %c\n", charTwo);
   return 0;
   

};
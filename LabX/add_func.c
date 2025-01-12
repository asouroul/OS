#include <stdio.h>
#include <stdlib.h>

void add(int *num1, int *num2, int *num3) {
  int sum;
  sum = *num1 + *num2 + *num3;
  printf("The sum is %d\n", sum);
}

int main () {

int integer1=10;
int integer2=20;
int integer3=12;

add(&integer1, &integer2, &integer3);

return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX_FACT 21

long long fact[MAX_FACT] = {1};
int nFact = 0;

/*Dynamic programming algorithm*/
long long factorial(int n) {
  if (n >= MAX_FACT) {
    printf("Number too large. Maximum supported is %d.\n", MAX_FACT - 1);
    return -1;
  }
  while (nFact < n)
      fact[++nFact] = nFact * fact[nFact - 1];
  return fact[n];
}

int main() {
  int number;

  printf("Enter number, to exit enter -1\n");
  scanf("%d", &number);
  while (number > -1) {
    long long result = factorial(number);
    if (result != -1)
      printf("%d! = %lld\n", number, result);
    printf("Enter number, to exit enter -1\n");
    scanf("%d", &number);
  }

  return 0;
}

#include <stdio.h>

long long power(int base, int exponent){
  return !exponent ? 1 : base * power(base, exponent - 1);
}

int main(){
  int base, exponent;
  printf("Enter base and exponent, to exit enter -1\n");
  scanf("%d %d", &base, &exponent);
  while (base > -1){
    long long pow = power(base, exponent);
    printf("%d^%d = %lld\n", base, exponent, pow);
    printf("Enter base and exponent, to exit enter -1\n");
    scanf("%d %d", &base, &exponent);
  }
}
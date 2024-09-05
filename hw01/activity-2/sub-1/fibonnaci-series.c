#include <stdio.h>

void fibonnaci(int n){
  int i = 0, p = 0, s = 1;
  printf("%d", p);
  while (i++ < n){
    s += p;
    p = s - p;
    printf(" %d", s);
  }
  printf("\n");
}

int main(){
  int number;
  printf("Enter number, to exit enter -1\n");
  scanf("%d", &number);
  while (number > -1){
    fibonnaci(number);  
    printf("Enter number, to exit enter -1\n");
    scanf("%d", &number);
  }
  return 0;
}
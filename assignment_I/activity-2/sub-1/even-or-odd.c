#include <stdio.h>
#include <string.h>

int isEven(int n){
  return ! (n % 2);
}

int main(){
  int number;
  char txt[5];
  printf("Enter number, to exit enter -1\n");
  scanf("%d", &number);
  while (number > -1){
    printf("%d\n", isEven(number));
    if (isEven(number))
      strcpy(txt, "even");
    else
      strcpy(txt, "odd");
    
    printf("%d is %s number\n", number, txt);
    printf("Enter number, to exit enter -1\n");
    scanf("%d", &number);
  }
  
  return 0;
}
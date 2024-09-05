#include <stdio.h>

int IsUppercase(char c){
  return 64 <= c && c <= 90;
}

int main(){
  char letter;
  printf("Enter letter, to exit enter '&' \n");
  scanf("%c", &letter);
  while (letter != '&'){
    fflush(stdin);
    printf("'%c' Is", letter);
    if(!IsUppercase(letter))
      printf("n't");
    printf(" uppercase letter\n");
    printf("Enter letter, to exit enter '&' \n");
    scanf("%c", &letter);
  }
  return 0;
}
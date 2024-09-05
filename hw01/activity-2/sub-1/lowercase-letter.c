#include <stdio.h>

int IsLowercase(char c){
  return 97 <= c && c <= 122;
}

int main(){
  char letter;
  printf("Enter letter, to exit enter '&' \n");
  scanf("%c", &letter);
  while (letter != '&'){
    fflush(stdin);
    printf("'%c' Is", letter);
    if(!IsLowercase(letter))
      printf("n't");
    printf(" lower letter\n");
    printf("Enter letter, to exit enter '&' \n");
    scanf("%c", &letter);
  }
  return 0;
}
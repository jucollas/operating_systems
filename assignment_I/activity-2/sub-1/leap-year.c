#include <stdio.h>

int isLeap(int y){
  return !(y % 4) && !(!(y % 100) && (y % 400));
}

int main(){
  int year;
  printf("Enter a year of the Gregorina calendar, to exit enter -1\n");
  scanf("%d", &year);
  while(year != -1){
    if (isLeap(year)){
      printf("Is leap year\n");
    }else{
      printf("Isn't leap year\n");
    }
    printf("Enter a year of the Gregorina calendar, to exit enter -1\n");
    scanf("%d", &year);
  }
}
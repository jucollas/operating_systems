#include <stdio.h>
#include <limits.h>

int main(){
  int n, ans, aux, i;
  printf("Enter number dates, to exit enter 0\n");
  scanf("%d", &n);
  while(n > 0){
    ans = INT_MIN;
    for(i = 0; i < n; ++i){
      scanf("%d", &aux);
      if (aux > ans)
        ans = aux;
    }
    printf("The grater number is %d\n", ans);
    printf("Enter number dates, to exit enter 0\n");
    scanf("%d", n);
  }
  return 0;
}
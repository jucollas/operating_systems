#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* log_b(x) = log_e(x)/ log_e(b) */
double logBase(double x, double base) {
  return log(x) / log(base);
}

char digits(int n) {
  return n < 10 ? n + '0' : n + 'A' - 10;
}

char* changeBase(int n, int base) {
  if (n == 0) {
    char* zero = (char*) malloc(2 * sizeof(char));
    strcpy(zero, "0");
    return zero;
  }

  int length = (int)(logBase(n, base)) + 2;
  char* ans = (char*) malloc(length * sizeof(char));
  int aux = n, i = 0, j;
  
  while (aux > 0) {
    ans[i++] = digits(aux % base);
    aux /= base;
  }
  ans[i] = '\0';

  for (j = 0; j < i / 2; j++) {
    char tmp = ans[j];
    ans[j] = ans[i - j - 1];
    ans[i - j - 1] = tmp;
  }
  
  return ans;
}

int main() {
  int n, i;
  printf("Enter a number, to exit enter 0: ");
  scanf("%d", &n);

  while (n > 0) {
    int oct_len = strlen(changeBase(n, 8)) + 1;
    int dec_len = (int)(log10(n)) + 2;
    int hex_len = strlen(changeBase(n, 16)) + 1;

    printf("|%-*s|%-*s|%-*s|\n", oct_len, "oct", dec_len, "dec", hex_len, "hex");

    for (i = 1; i <= n; ++i) {
      char* oct_str = changeBase(i, 8);
      char* hex_str = changeBase(i, 16);
      printf("|%-*s|%-*d|%-*s|\n", oct_len, oct_str, dec_len, i, hex_len, hex_str);
      free(oct_str);
      free(hex_str);
    }

    printf("Enter a number, to exit enter 0: ");
    scanf("%d", &n);
  }

  return 0;
}

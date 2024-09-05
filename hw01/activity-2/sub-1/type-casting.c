#include <stdio.h>

int main() {
    // Implicit Type Casting
    int a = 10;
    float b = a;  
    double c = b; 
    short d = a;  
    char e = a; 

    // Explicit Type Casting
    float f = 5.75;
    int g = (int)f;  
    double h = (double)a; 
    short i = (short)c;   
    char j = (char)f;     

    // Print results for implicit conversions
    printf("Implicit Type Casting:\n");
    printf("int to float: %d -> %f\n", a, b);
    printf("float to double: %f -> %lf\n", b, c);
    printf("int to short: %d -> %d\n", a, d);
    printf("int to char: %d -> %c\n", a, e);

    // Print results for explicit conversions
    printf("\nExplicit Type Casting:\n");
    printf("float to int: %f -> %d\n", f, g);
    printf("int to double: %d -> %lf\n", a, h);
    printf("double to short: %lf -> %d\n", c, i);
    printf("float to char: %f -> %c\n", f, j);

    return 0;
}

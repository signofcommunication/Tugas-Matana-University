#include <stdio.h>

int main(void) {
    double A, B;
    scanf("%lf %lf", &A, &B);

    double discount = ((A - B) / A) * 100.0; 
    
    printf("%.2lf %%\n", discount);
}


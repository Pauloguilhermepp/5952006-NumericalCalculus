#include "methods.h"
#include <math.h>

#define N_FUNCS (1)

double f1(double x)
{
    return cos(x) - x;
}

int main()
{
    double A, B, E;
    scanf("%lf %lf %lf", &A, &B, &E);

    double (*functions[])(double) = {
        f1
    };

    printf("\nTesting bissection method:\n");
    for (int i = 0; i < N_FUNCS; i++) 
    {
        double a = A, b = B;
        bissectionMethod(&a, &b, E, functions[i]);
        printf("Function #%d result: x*E[%lf, %lf]\n", i + 1, a, b);
    }
    
    printf("\nTesting secants method:\n");
    for (int i = 0; i < N_FUNCS; i++) 
    {
        double a = A, b = B;
        int flag;
        double x = secantsMethod(a, b, E, 10, functions[i], &flag);
        printf("Function #%d result: x=~%lf\nflag=%d\n", i + 1, x, flag);
    }
    
    printf("\nTesting Regula Falsi method:\n");
    for (int i = 0; i < N_FUNCS; i++) 
    {
        double a = A, b = B;
        int flag;
        double x = regulaFalsiMethod(a, b, E, 10, functions[i], &flag);
        printf("Function #%d result: x=~%lf\nflag=%d\n", i + 1, x, flag);
    }
}
#include "methods.h"
#include <math.h>

// Method to find the solution using the bissection method
void bissectionMethod(double* lower, double* upper, double epsilon, double(*func)(double))
{
    // Defining maximum number of iterations:
    int maxNumIt = ceil(log2(*upper - *lower) - log2(epsilon));

    for (int i = 0; i < maxNumIt; i++) 
    {
        // Let x be the middle point of the interval [lower, upper]:
        double x = (*lower + *upper)/2;

        if (func(*lower) * func(x) < 0)
        {
            *upper = x;
        }
        else
        {
            *lower = x;
        }
    }
    
    printf("Number of iterations: %d\n", maxNumIt);
}

double secantsMethod(double lower, double upper, double epsilon, int nMaxIt, double(*func)(double), int* flag)
{
    // Setting a flag value to test if the nMaxIt was achieved:
    *flag = 0;

    double x0 = lower;
    double x1 = upper;
    double aux;
    double fx0 = func(x0);

    for(int i = 0; i < nMaxIt; i++)
    {
        double fx1 = func(x1);
        if (fabs(x0 - x1)/fabs(x1) < epsilon)
        {
            printf("Number of iterations: %d\n", i);
            return x1;
        }

        aux = x1;
        x1 = (x0*fx1 - x1*fx0) / (fx1 - fx0);
        x0 = aux;
        fx0 = fx1;
    }

    *flag = 1;
    return x1;
}

double regulaFalsiMethod(double lower, double upper, double epsilon, int nMaxIt, double(*func)(double), int* flag)
{
    // Setting a flag value to test if the nMaxIt was achieved:
    *flag = 0;

    double x2;
    double aux;
    double fUpper = func(upper);
    double fLower = func(lower);

    for(int i = 0; i < nMaxIt; i++)
    {
        x2 = (lower*fUpper - upper*fLower) / (fUpper - fLower);
        double fx2 = func(x2);

        if (fabs(lower - x2)/fabs(x2) < epsilon || fabs(upper - x2)/fabs(x2) < epsilon)
        {
            printf("Number of iterations: %d\n", i+1);
            return x2;
        }

        if (fx2 * fLower < 0) 
        {
            upper = x2;
            fUpper = fx2;
        }
        else
        {
            lower = x2;
            fLower = fx2;
        }
    }

    *flag = 1;
    return x2;
}
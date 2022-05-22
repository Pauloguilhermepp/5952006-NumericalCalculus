#include <math.h>
#include <stdio.h>

void bissectionMethod(double* lower, double* upper, 
    double epsilon, double(*func)(double)) {
    
    int maxNumberofIterations = ceil(log2(*upper - *lower) - log2(epsilon));

    for (int i = 0; i < maxNumberofIterations; i++)  {
        // Let x be the middle point of the interval [lower, upper]:
        double x = (*lower + *upper)/2;

        // Bissect interval:
        if (func(*lower) * func(x) < 0) *upper = x;
        else *lower = x;
    }

    printf("Number of iterations: %d\n", maxNumberofIterations);
}

double secantsMethod(double lower, double upper, double epsilon, 
    int maxNumberofIterations, double(*func)(double), int* flag) {
    
    // Flag to check if the maxNumberofIterations was achieved:
    *flag = 0;
    
    double x0 = lower, x1 = upper, fx0 = func(x0), aux;

    for (int i = 0; i < maxNumberofIterations; i++) {
        double fx1 = func(x1);

        // Stop if aproximate relative error is acceptable, or f(x) is close enough:
        if (fabs(x0 - x1)/fabs(x1) < epsilon || fabs(fx1) < epsilon){
            printf("Number of iterations: %d\n", i);
            return x1;
        }
        aux = x1;
        // New x is the insersection between the line that passes through 
        // x0 and x1, and the horizontal axis:
        x1 = (x0*fx1 - x1*fx0) / (fx1 - fx0);
        x0 = aux;
        fx0 = fx1;
    }

    *flag = 1;
    return x1;
}

double regulaFalsiMethod(double lower, double upper, double epsilon, 
    int maxNumberofIterations, double(*func)(double), int* flag) {
    
    // Flag to check if the maxNumberofIterations was achieved:
    *flag = 0;

    double x2, aux, fUpper = func(upper), fLower = func(lower);

    for (int i = 0; i < maxNumberofIterations; i++) {
        x2 = (lower*fUpper - upper*fLower) / (fUpper - fLower);
        double fx2 = func(x2);

        if (fabs(lower - x2)/fabs(x2) < epsilon || fabs(upper - x2)/fabs(x2) < epsilon){
            printf("Number of iterations: %d\n", i);
            return x2;
        }

        // Divide interval at the intersection with the secant line:
        if (fx2 * fLower < 0)  { 
            upper = x2; 
            fUpper = fx2; 
        } else {
            lower = x2;
            fLower = fx2;
        }
    }

    *flag = 1;
    return x2;
}

double f1(double x) { return cos(x) - x; }

int main() {

    // INPUTS
    // A: lower bound of interval of interest
    // B: upper bound of interval of interest
    // E: accepted error (epsilon)
    double A, B, E, a, b, x;
    int flag;
    scanf("%lf %lf %lf", &A, &B, &E);

    printf("\nTesting bissection method:\n");
    a = A; b = B;
    printf("%lf %lf\n", a, b);
    bissectionMethod(&a, &b, E, f1);
    printf("Function result: x*E[%lf, %lf]\n", a, b);
    
    printf("\nTesting secants method:\n");
    a = A; b = B;
    printf("%lf %lf\n", a, b);
    x = secantsMethod(a, b, E, 10, f1, &flag);
    printf("Function result: x=~%lf\nflag=%d\n", x, flag);
    
    printf("\nTesting Regula Falsi method:\n");
    a = A; b = B;
    printf("%lf %lf\n", a, b);
    x = regulaFalsiMethod(a, b, E, 10, f1, &flag);
    printf("Function result: x=~%lf\nflag=%d\n", x, flag);
}
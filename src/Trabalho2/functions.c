#include <stdio.h>
#include <math.h>
#include "functions.h"

double f1(double x) {
    return pow(M_E, -x*x/2);
}

double simpsonOneThird(double a, double b, int n, double (*fPtr)(double)) {

    // if n isn't odd, abort
    if (n % 2 == 0) {
        printf("'n' must be odd\nAborting...");
        exit(1);
    }

    // 'h' is the width of each subinterval
    double h = (b - a)/(n - 1);

    // f(a) and f(b) appears only once in the summation
    double sum = fPtr(a) + fPtr(b);

    // summation of other terms
    for (int i = 1; i < n - 1; i++) {

        // if it's odd, multiply by 4 and add to the sum
        // if it's even, multiply by 2 and add to the sum
        if (i % 2 == 1) {
            sum += 4 * fPtr(a + i*h);
        } else {
            sum += 2 * fPtr(a + i*h);
        }
    }

    // return result
    return h * sum / 3;

}
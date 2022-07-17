/*
 * main.c
 *
 * Authors (in alphabetical order):
 * BERGOC, Gabriel
 * PEREIRA, Paulo
 * SANTOS, Lucas dos
 * 
 * Copyright: free software, provided the original authorship is specified.
 */

#include <stdio.h>
#include "functions.h"

int main(int argc, char *argv[]) {

    double a, b;
    int n, f;

    double (*fPtrs[])(double) = {
        f1
    };

    printf("Welcome to Simpson's 1/3 Rule calculator. Please Enter:\n");
    printf("Lower integration limit (double): ");
    scanf("%lf", &a);
    printf("Upper integration limit (double): ");
    scanf(" %lf", &b);
    printf("Number of points to divide interval (int - MUST BE ODD): ");
    scanf(" %d", &n);
    printf("Index of function of following list (int):\n"
           "1) f(x) = e^(-x^2/2)\n"
           "Choice: ");
    scanf(" %d", &f);

    printf("\nResult: %lf", simpsonOneThird(a, b, n, fPtrs[f - 1]));

    return 0;
}
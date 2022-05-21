#ifndef BISSECCAO_H
#define BISSECCAO_H
#include <stdio.h>

void bissectionMethod(double* lower, double* upper, double epsilon, double(*func)(double));

double secantsMethod(double lower, double upper, double epsilon, int nMaxIt, double(*func)(double), int* flag);

double regulaFalsiMethod(double lower, double upper, double epsilon, int nMaxIt, double(*func)(double), int* flag);


#endif // BISSECCAO_H
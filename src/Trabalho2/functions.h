#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * @brief Function that calculates an aproximation of a definite integral by
 * the Simpson's 1/3 rule.
 * 
 * @param a Lower limit of integration.
 * @param b Upper limit of integration.
 * @param n Odd integer corresponding to the number of points to equally divide
 * the interval [a, b].
 * @param fPtr Pointer to function f, which is the integrand to approximate.
 * @return double Approximation of integral of f(x)dx from a to b.
 */
double simpsonOneThird(double a, double b, int n, double (*fPtr)(double));

/**
 * @brief Function: f(x) = e^(-x^2/2)
 * 
 * @param x Independent variable 'x'.
 * @return double Dependent variable 'f(x)'.
 */
double f1(double x);

#endif // FUNCTIONS_H
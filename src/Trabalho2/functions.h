#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * @brief Function that calculates an aproximation of a definite integral by
 * the Simpson's 1/3 rule.
 * 
 * @param a Begining of interval of interest.
 * @param b End of interval of interest.
 * @param n Odd integer corresponding to the number of points to equally divide
 * the interval [a, b].
 * @param fPtr Pointer to function f, which is the integrand to approximate.
 * @return double Approximation of integral of f(x)dx from a to b.
 */
double simpsonOneThird(double a, double b, int n, double (*fPtr)(double));

#endif // FUNCTIONS_H
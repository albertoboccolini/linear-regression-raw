#ifndef REGRESSION_H
#define REGRESSION_H

double calculate_slope(double x[], double y[], int n);
double calculate_intercept(double x[], double y[], int n, double slope);
double predict(double x, double slope, double intercept);
double calculate_mse(double *x, double *y, int n, double slope, double intercept);

#endif

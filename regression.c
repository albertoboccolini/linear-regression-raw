#include "regression.h"
#include <stdio.h>
#include "utils.h"

double calculate_slope(double x[], double y[], int n) {
    double sum_x = sum(x, n);
    double sum_y = sum(y, n);
    double sum_xy = 0.0;
    double sum_x2 = 0.0;

    for (int i = 0; i < n; i++) {
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    return (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
}

double calculate_intercept(double x[], double y[], int n, double slope) {
    double sum_x = sum(x, n);
    double sum_y = sum(y, n);
    return (sum_y - (slope * sum_x)) / n;
}

double calculate_mse(double *x, double *y, int n, double slope, double intercept) {
    double mse = 0.0;

    for (int i = 0; i < n; i++) {
        double prediction = slope * x[i] + intercept;
        double error = y[i] - prediction;
        mse += error * error;
    }

    return mse / n;
}

double predict(double x, double slope, double intercept) {
    return slope * x + intercept;
}

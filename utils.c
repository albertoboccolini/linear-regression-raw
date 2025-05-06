#include "utils.h"

double sum(double values[], int n) {
    double total = 0.0;

    for (int i = 0; i < n; i++) {
        total += values[i];
    }

    return total;
}

double mean(double values[], int n) {
    if (n == 0) {
        return 0.0;
    }
    
    return sum(values, n) / n;
}

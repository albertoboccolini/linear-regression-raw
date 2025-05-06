#include <stdio.h>
#include "regression.h"
#include "data_loader.h"
#include "utils.h"

#define MAX_ROWS 1000

int main() {
    double data[MAX_ROWS][MAX_COLS];
    int n_rows = 0;
    int n_cols = 0;
    const char* filename = "student_data.txt";

    int result = load_dataset(filename, data, &n_rows, &n_cols);

    if (result != 0) {
        printf("Errore nel caricamento del file: %s\n", filename);
        return 1;
    }

    printf("Dataset caricato correttamente: %d righe, %d colonne\n", n_rows, n_cols);

    for (int i = 1; i < n_rows && i < 6; i++) {
        printf("Riga %d:", i);
        
        for (int j = 0; j < n_cols; j++) {
            printf(" %.2f", data[i][j]);
        }

        printf("\n");
    }

    double x[n_rows];
    double y[n_rows];

    for (int h = 0; h < n_rows; h++) {
        x[h] = data[h][2]; // total_units
        y[h] = data[h][4]; // total_study_time
    }


    double slope = calculate_slope(x, y, n_rows);
    double intercept = calculate_intercept(x, y, n_rows, slope);

    double new_data = 6;
    double prediction = predict(new_data, slope, intercept);


    printf("\nSlope: %.4f\n", slope);
    printf("Intercept: %.4f\n", intercept);
    printf("Prediction: %.4f\n", prediction);

    return 0;
}

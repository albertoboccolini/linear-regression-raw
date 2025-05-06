#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "regression.h"
#include "data_loader.h"
#include "utils.h"

#define MAX_ROWS 1000

double data[MAX_ROWS][MAX_COLS];
int n_rows = 0, n_cols = 0;
double slope = 0, intercept = 0;
int dataset_loaded = 0;

void load_dataset_cli() {
    system("clear");
    const char* filename = "student_data.txt";
    int result = load_dataset(filename, data, &n_rows, &n_cols);

    if (result != 0) {
        printf("Error loading file: %s\n", filename);
        return;
    }

    printf("Dataset loaded: %d rows, %d columns\n", n_rows, n_cols);
    dataset_loaded = 1;
}

void regression_and_prediction() {
    system("clear");
    if (!dataset_loaded) {
        printf("Please load the dataset first!\n");
        return;
    }

    double x[n_rows];
    double y[n_rows];
    for (int i = 0; i < n_rows; i++) {
        x[i] = data[i][11]; // quizzes_score_percentage
        y[i] = data[i][14]; // final_exam_score
    }

    slope = calculate_slope(x, y, n_rows);
    intercept = calculate_intercept(x, y, n_rows, slope);
    double mse = calculate_mse(x, y, n_rows, slope, intercept);

    printf("Regression computed: slope = %.4f, intercept = %.4f\n", slope, intercept);
    printf("Mean Squared Error (MSE): %.4f\n", mse);

    double quiz_input;
    printf("\nEnter student's quiz percentage (30-100): ");
    scanf("%lf", &quiz_input);

    while (quiz_input < 30 || quiz_input > 100) {
        printf("Invalid input. Please enter a value between 30 and 100: ");
        scanf("%lf", &quiz_input);
    }

    double prediction = predict(quiz_input, slope, intercept);
    printf("Predicted final exam score: %.2f\n", prediction);
}

void exit_program() {
    printf("\nExiting program.\n");
    exit(0);
}

void menu() {
    int gIndex;
    int valid_input;
    printf("\n----------------------------------------------\n");
    printf("| Linear Regression Raw by Alberto Boccolini |\n");
    printf("----------------------------------------------\n");

    do {
        freopen(NULL, "rb", stdin);
        printf("\nSelection Menu\n");
        printf("1 - Load dataset\n");
        printf("2 - Compute regression and predict score\n");
        printf("3 - Exit\n");
        printf("\nEnter your choice: ");

        valid_input = scanf("%i", &gIndex);

        while (gIndex < 1 || gIndex > 3 || !valid_input) {
            freopen(NULL, "rb", stdin);
            printf("\nError: Invalid number.\n");
            printf("Enter your choice: ");
            valid_input = scanf("%i", &gIndex);
        }

        switch (gIndex) {
            case 1:
                load_dataset_cli();
                break;
            case 2:
                regression_and_prediction();
                break;
            case 3:
                exit_program();
                break;
        }

    } while (1);
}

int main() {
    srand(time(NULL));
    menu();
    return 0;
}

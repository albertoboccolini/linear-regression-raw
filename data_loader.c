#include "data_loader.h"
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_loader.h"

int load_dataset(const char* filename, double data[][MAX_COLS], int* n_rows, int* n_cols) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Errore apertura file");
        return -1;
    }

    char line[MAX_LINE_LEN];
    int row = 0;
    *n_cols = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '\n' || line[0] == '#') continue;

        char* token = strtok(line, ",\t\n ");
        int col = 0;

        while (token != NULL && col < MAX_COLS) {
            data[row][col] = strtod(token, NULL);
            token = strtok(NULL, ",\t\n ");
            col++;
        }

        if (col > *n_cols) {
            *n_cols = col;
        }

        row++;
    }

    fclose(file);
    *n_rows = row;
    return 0;
}

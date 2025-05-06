#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#define MAX_COLS 32
#define MAX_LINE_LEN 1024

int load_dataset(const char* filename, double data[][MAX_COLS], int* n_rows, int* n_cols);

#endif

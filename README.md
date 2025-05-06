# Linear Regression Raw

This is a simple linear regression algorithm in C used to predict students `total_study_time` based on `total_units` trained on [student-engagement-and-performance dataset](https://huggingface.co/datasets/vunderkind/student-engagement-and-performance).

## Getting started

- Compile the project

```sh
    gcc -Wall -Wextra -pedantic main.c data_loader.c utils.c regression.c -o student_model
```

- Run the `student_model` file

```sh
    ./student_model
```

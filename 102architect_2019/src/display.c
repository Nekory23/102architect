/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** display functions
*/

#include "my.h"

void display_result(float *coord, float *result_p, float *matrix)
{
    for (int i = 0; i != 9; i += 3)
        printf("%.2f\t%.2f\t%.2f\n", matrix[i], matrix[i + 1], matrix[i + 2]);
    printf("(%.2f, %.2f) => ", coord[0], coord[1]);
    printf("(%.2f, %.2f)\n", result_p[0], result_p[1]);
}

void display_transfo(int mode, char *arg1, char *arg2)
{
    switch (mode) {
    case 1 : printf("Translation along vector ");
        printf("(%.0f, %.0f)\n", atof(arg1), atof(arg2));
        break;
    case 2 : printf("Scaling by factors ");
        printf("%.0f and %.0f\n", atof(arg1), atof(arg2));
        break;
    case 3 : printf("Rotation by a %d degree angle\n", atoi(arg1));
        break;
    case 4 : printf("Reflection over an axis with an inclination angle of ");
        printf("%d degrees\n", atoi(arg1));
        break;
    }
}

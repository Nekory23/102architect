/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** create the different matrixes and the coordinates of the point
*/

#include "my.h"

float *create_empty_matrix(float *result_m)
{
    for (int i = 0; i != 9; i++) {
        result_m[i] = 0;
        if (i == 0 || i == 4 || i == 8)
            result_m[i] = 1;
    }
    return (result_m);
}

float *create_s_matrix(char *arg1, float *matrix)
{
    for (int i = 0; i != 9; i++) {    
        if (i == 0)
            matrix[i] = cos(2 * (atof(arg1) / 180 * M_PI));
        if (i == 1 || i == 3)
            matrix[i] = sin(2 * (atof(arg1) / 180 * M_PI));
        if (i == 4) {
            matrix[i] = -cos(2 * (atof(arg1) / 180 * M_PI));
            if (atoi(arg1) == 45)
                matrix[i] = 0;
        }
        if (i == 8)
            matrix[i] = 1;
    }
    display_transfo(4, arg1, "blank");
    return (matrix);
}

float *create_r_matrix(char *arg1, float *matrix)
{
    for (int i = 0; i != 9; i++) {
        matrix[i] = 0;
        if (i == 0 || i == 4)
            matrix[i] = cos(atof(arg1) / 180 * M_PI);
        if (i == 3)
            matrix[i] = sin(atof(arg1) / 180 * M_PI);
        if (i == 1)
            matrix[i] = -sin(atof(arg1) / 180 * M_PI);
        if (i == 8)
            matrix[i] = 1;
    }
    display_transfo(3, arg1, "blank");
    return (matrix);
}

float *create_t_z_matrix(char *arg1, char *arg2, float *matrix, int mode)
{
    for (int i = 0; i != 9; i++) {
        matrix[i] = 0;
        if (mode == 1) {
            if (i == 0 || i == 4)
                matrix[i] = 1;
            if (i == 2)
                matrix[i] = atof(arg1);
            if (i == 5)
                matrix[i] = atof(arg2);
        }
        if (mode == 2) {
            if (i == 0)
                matrix[i] = atof(arg1);
            if (i == 4)
                matrix[i] = atof(arg2);
        }
        if (i == 8)
            matrix[i] = 1;
    }
    display_transfo(mode, arg1, arg2);
    return (matrix);
}

float *create_coord(char *x, char *y, float *coord)
{
    coord[0] = atof(x);
    coord[1] = atof(y);
    coord[2] = 1;
    return (coord);
}

/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int my_strlen(char *str);
void help_display(void);
int error_handling_coordinates(int ac, char **av);
float *create_t_z_matrix(char *arg1, char *arg2, float *matrix, int mode);
float *create_s_matrix(char *arg1, float *matrix);
float *create_r_matrix(char *arg1, float *matrix);
float *create_empty_matrix(float *result_matrix);
float *create_coord(char *x, char *y, float *coord);
void display_result(float *coord, float *result_p, float *matrix);
void display_transfo(int mode, char *arg1, char *arg2);

#define ERROR_NBRARG "this program must have at least 2 coordinates and a transformation\n"
#define ERROR_COOR "the coordinates must be numbers\n"
#define ERROR_TRANSFO "transformation must be t z r or s\n"
#define ERROR_TRANSFOARG "the arguments for the transformation must be numbers\n"
#define ERROR_TRANSFOARGNBR "this transformation requires more or less factors\n"

#endif

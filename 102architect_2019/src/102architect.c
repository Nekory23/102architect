/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** compute the coordinates of a point after one or several transformations
*/

#include "my.h"

void compute_point(float *matrix, float *coord, float *result_p)
{
    float temp;

    for (int i = 0; i != 3 ; i++) {
        temp = 0;
        for (int j = 0; j != 3; j++)
            temp += coord[j] * matrix[j + 3 * i];
        result_p[i] = temp;
    }
    display_result(coord, result_p, matrix);
}

void architect(int ac, char **av, float *coord, float *matrix, float *result_p)
{
    int nbr = 3;

    coord = create_coord(av[1], av[2], coord);
    while (nbr != ac) {
        if (av[nbr][1] == 't' || av[nbr][1] == 'z') {
            if (av[nbr][1] == 't')
                matrix = create_t_z_matrix(av[nbr + 1], av[nbr + 2], matrix, 1);
            if (av[nbr][1] == 'z')
                matrix = create_t_z_matrix(av[nbr + 1], av[nbr + 2], matrix, 2);
            nbr = nbr + 3;
        }
        else if (av[nbr][1] == 'r' || av[nbr][1] == 's') {
            if (av[nbr][1] == 'r')
                matrix = create_r_matrix(av[nbr + 1], matrix);
            if (av[nbr][1] == 's')
                matrix = create_s_matrix(av[nbr + 1], matrix);
            nbr = nbr + 2;
        }
    }
    compute_point(matrix, coord, result_p);
}

int main(int ac, char **av)
{
    float matrix[9];
    float coord[3];
    float result_p[3];

    if (ac == 2 && my_strlen(av[1]) == 2 && av[1][0] == '-'
        && av[1][1] == 'h') {
        help_display();
        return (0);
    }
    if (ac < 4) {
        write(2, ERROR_NBRARG, my_strlen(ERROR_NBRARG));
        return (84);
    }
    if (error_handling_coordinates(ac, av) == 84)
        return (84);
    architect(ac, av, coord, matrix, result_p);
    return (0);
}

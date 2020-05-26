/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** error handling for the 102 architect
*/

#include "my.h"

int error_handling_transfo_coord(int ac, char **av, int nbr, int j)
{
    int k = nbr + j;
    int i;

    if (ac < k) {
        write(2, ERROR_TRANSFOARGNBR, my_strlen(ERROR_TRANSFOARGNBR));
        return (84);
    }
    for (; nbr != k; nbr++) {
        i = 0;
        while (av[nbr][i] != '\0') {
            if ((av[nbr][i] >= '0' && av[nbr][i] <= '9') ||
                av[nbr][i] == '-' || av[nbr][i] == '.')
                i = i + 1;
            else {
                write (2, ERROR_TRANSFOARG, my_strlen(ERROR_TRANSFOARG));
                return (84);
            }
        }
    }
    return (nbr);
}

int error_handling_transfo(int ac, char **av, int nbr)
{
    while (nbr != ac) {
        if (my_strlen(av[nbr]) == 2 && av[nbr][0] == '-') {
            if (av[nbr][1] == 't' || av[nbr][1] == 'z')
                nbr = error_handling_transfo_coord(ac, av, nbr + 1, 2);
            else if (av[nbr][1] == 'r' || av[nbr][1] == 's')
                nbr = error_handling_transfo_coord(ac, av, nbr + 1, 1);
            else {
                write(2, ERROR_TRANSFO, my_strlen(ERROR_TRANSFO));
                return (84);
            }
        }
        if (nbr == ac)
            return (0);
        if (nbr == 84)
            return (84);
        if (my_strlen(av[nbr]) != 2 || av[nbr][0] != '-') {
            write(2, ERROR_TRANSFO, my_strlen(ERROR_TRANSFO));
            return (84);
        }
    }
    return (0);
}

int error_handling_coordinates(int ac, char **av)
{
    int i;
    int nbr;
    
    for (nbr = 1; nbr != 3; nbr++) {
        i = 0;
        while (av[nbr][i] != '\0') {
            if ((av[nbr][i] >= '0' && av[nbr][i] <= '9') ||
                av[nbr][i] == '.' || av[nbr][i] == '-')
                i = i + 1;
            else {
                write(2, ERROR_COOR, my_strlen(ERROR_COOR));
                return (84);
            }
        }
    }
    if (error_handling_transfo(ac, av, nbr) == 84)
        return (84);
    return (0);
}

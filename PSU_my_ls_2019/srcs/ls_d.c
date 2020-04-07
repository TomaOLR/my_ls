/*
** EPITECH PROJECT, 2020
** ls_d.c
** File description:
** Thomas Olry's ls_d.c made the 01/07/2020
*/

#include "ls.h"

int ls_d(int ac, char **av)
{
    int x = 0;
    int i = 1;

    if (ac == 2) {
        my_putstr(".\n");
        exit (0);
    }
    for (; av[i] != NULL; i += 1, x += 1) {
        if (x != 0 && my_strcmp(av[i], "-d") != 0)
            my_putchar(' ');
        if (is_reg(av[i]) == 0 && is_dir(av[i]) == 0)
            perror(av[i]);
        else if (my_strcmp(av[i], "-d") != 0)
            my_putstr(av[i]);
    }
    if (is_reg(av[i]) != 0 || is_dir(av[i]) != 0)
        my_putchar('\n');
    return (0);
}

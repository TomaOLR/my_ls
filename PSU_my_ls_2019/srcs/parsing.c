/*
** EPITECH PROJECT, 2020
** parsing.c
** File description:
** Thomas Olry's parsing.c made the 01/10/2020
*/

#include "ls.h"

void simple_case(int ac, char **av)
{
    int x = 0;

    if (ac == 1)
        read_directory(".");
    else if (ac == 2 && av[1][0] != '-')
        read_directory(av[1]);
    for (int i = 0; av[i] != NULL; i += 1) {
        if (av[i][0] == '-')
            x = 1;
    }
    if (x == 0)
        multi_directory(ac, av);
}

void flags(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-l") == 0)
        ls_listing(".");
    if (ac == 3 && my_strcmp(av[1], "-l") == 0)
        ls_listing(av[2]);
    if (ac == 2 && my_strcmp(av[1], "-r") == 0)
        ls_r(".");
    if (ac == 3 && my_strcmp(av[1], "-r") == 0)
        ls_r(av[2]);
    if (ac == 2 && my_strcmp(av[1], "-t") == 0)
        ls_time(put_in_tab("."));
    if (ac == 3 && my_strcmp(av[1], "-t") == 0)
        ls_time(put_in_tab(av[2]));
}

/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Thomas Olry's main.c made the 12/30/2019
*/

#include "ls.h"

int parsing(int ac, char **av)
{
    for (int i = 0; av[i] != NULL; i += 1) {
        if (my_strcmp(av[i], "-d") == 0)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    simple_case(ac, av);
    flags(ac, av);
    if (parsing(ac, av) == 1)
        ls_d(ac, av);
    return (0);
}

/*
** EPITECH PROJECT, 2020
** recursive.c
** File description:
** Thomas Olry's recursive.c made the 01/06/2020
*/

#include "ls.h"

int recursive(char *file)
{
    struct dirent *rd;
    DIR *dir = opendir(file);

    if (dir == NULL)
        exit (0);
    my_putstr(file);
    my_putstr(":\n");
    while (rd = readdir(dir)) {
        my_putchar (' ');
        if (rd->d_name[0] != '.' && is_dir(rd->d_name) == 0)
            my_putstr(rd->d_name);
        else if (rd->d_name[0] != '.' && is_dir(rd->d_name) == 1)
            recursive(rd->d_name);
        my_putchar('\n');
    }
    exit (0);
}

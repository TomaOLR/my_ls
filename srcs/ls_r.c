/*
** EPITECH PROJECT, 2020
** ls_r.c
** File description:
** Thomas Olry's ls_r.c made the 01/09/2020
*/

#include "ls.h"

char **put_in_tab_r(char *file)
{
    struct dirent *rd;
    int i = 0;
    char **tab = malloc(sizeof(char *) * 1000);
    char *new_file;
    DIR *dir = opendir(file);

    if (file[my_strlen(file)] != '/')
        new_file = add_dir(file);
    check_dir(dir, file);
    while (rd = readdir(dir)) {
        tab[i] = malloc(sizeof(char) * my_strlen(rd->d_name) + 1);
        if (rd->d_name[0] != '.') {
            tab[i] = rd->d_name;
            i++;
        }
    }
    tab[i] = NULL;
    closing(dir);
    return (tab);
}

int ls_r(char *file)
{
    char **tab = put_in_tab_r(file);
    int i = 0;
    int x = 0;

    for (; tab[i] != NULL; i++);
    i -= 1;
    for (; i != -1; i -= 1, x += 1) {
        if (x != 0)
            my_putchar(' ');
        my_putstr(tab[i]);
    }
    my_putchar('\n');
    return (0);
}

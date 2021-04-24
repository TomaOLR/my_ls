/*
** EPITECH PROJECT, 2020
** ls_t.c
** File description:
** Thomas Olry's ls_t.c made the 01/07/2020
*/

#include "ls.h"
#include <string.h>

char *add_dir(char *file)
{
    int len = my_strlen(file);
    char *res = NULL;
    int i = 0;

    res = malloc(sizeof(char) * len + 2);
    for (; i != len; i += 1)
        res[i] = file[i];
    res[i] = '/';
    res[i + 1] = '\0';
    return (res);
}

char **put_in_tab(char *file)
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
            tab[i] = my_strcat(new_file, rd->d_name);
            i++;
        }
    }
    tab[i] = NULL;
    closing(dir);
    return (tab);
}

int the_date(char *file)
{
    struct stat date;
    stat(file, &date);
    return (date.st_mtime);
}

void print_ls_t(char **tab)
{
    int x = 0;
    int i = 0;

    for (int j = 0; tab[j] != NULL; j += 1, x += 1, i = 0) {
        if (x != 0)
            my_putchar(' ');
        for (; tab[j][i - 1] != '/'; i += 1);
        for (; tab[j][i] != '\0'; i += 1)
            my_putchar(tab[j][i]);
    }
    my_putchar('\n');
}

int ls_time(char **tab)
{
    int i = 0;
    char *str = NULL;

    for (; tab[i] != NULL; i += 1) {
        if (the_date(tab[i]) < the_date(tab[i + 1])) {
            str = malloc(sizeof(char) * my_strlen(tab[i]) + 1);
            str = my_strcpy(str, tab[i]);
            tab[i] = my_strcpy(tab[i], tab[i + 1]);
            tab[i + 1] = my_strcpy(tab[i + 1], str);
            i = 0;
        }
    }
    print_ls_t(tab);
    return (0);
}

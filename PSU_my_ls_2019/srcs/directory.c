/*
** EPITECH PROJECT, 2019
** directory.c
** File description:
** Thomas Olry's directory.c made the 12/30/2019
*/

#include "ls.h"

int is_dir(char *file)
{
    struct stat dir;
    stat(file, &dir);
    return (S_ISDIR(dir.st_mode));
}

int is_reg(char *file)
{
    struct stat reg;
    stat(file, &reg);
    return (S_ISREG(reg.st_mode));
}

int check_dir(DIR *dir, char *file)
{
    if (dir == NULL) {
        perror(file);
        exit (0);
    }
}

int read_directory(char *file)
{
    struct dirent *rd;
    DIR *dir = opendir(file);
    int x = 0;

    check_dir(dir, file);
    while (rd = readdir(dir)) {
        if (rd->d_name[0] != '.') {
            if (x != 0)
                my_putchar(' ');
            my_putstr(rd->d_name);
            x++;
        }
    }
    my_putchar('\n');
    closedir(dir);
    if (dir == NULL)
        exit (84);
    return (0);
}

int multi_directory(int ac, char **av)
{
    int i = 1;
    DIR *dir;

    for (; i != ac && ac > 2 && av[i][0] != '-'; i += 1) {
        dir = opendir(av[i]);
        if (dir != NULL){
            my_putstr(av[i]);
            my_putstr(":\n");
            read_directory(av[i]);
        }
        else if (dir == NULL && is_reg(av[i]) == 0)
            perror(av[i]);
        else {
            my_putstr(av[i]);
            my_putchar('\n');
        }
        if (i != ac - 1)
            my_putchar('\n');
    }
}

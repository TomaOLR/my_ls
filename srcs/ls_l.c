/*
** EPITECH PROJECT, 2019
** ls_l.c
** File description:
** Thomas Olry's ls_l.c made the 12/30/2019
*/

#include "ls.h"

int print_date(struct stat st)
{
    int x = 0;

    for (int i = 4; x != 2; i += 1) {
        if (ctime(&st.st_mtime)[i] == ':')
            x += 1;
        if (x == 2)
            return (0);
        my_putchar(ctime(&st.st_mtime)[i]);
    }
    return (0);
}

void stats(struct stat s, struct dirent *r, struct passwd *i, struct group *g)
{
    my_put_nbr(s.st_nlink);
    my_putchar(' ');
    my_putstr(i->pw_name);
    my_putchar(' ');
    my_putstr(g->gr_name);
    my_putchar(' ');
    my_put_nbr(s.st_size);
    my_putchar(' ');
    print_date(s);
    my_putchar(' ');
    my_putstr(r->d_name);
    my_putchar('\n');
}

void closing(DIR *dir)
{
    closedir(dir);
    if (dir == NULL)
        exit (84);
}

char *formate_file(DIR *dir, char *file, char *new_file)
{
    check_dir(dir, file);
    if (file[my_strlen(file)] != '/')
        new_file = add_dir(file);
    return (new_file);
}

int ls_listing(char *file)
{
    struct dirent *rd;
    struct stat st;
    struct passwd *passwd;
    struct group  *grp;
    char *new_file = NULL;
    char *res = NULL;
    DIR *dir = opendir(file);

    new_file = formate_file(dir, file, new_file);
    while (rd = readdir(dir)) {
        if (rd->d_name[0] != '.') {
            res = my_strcat(new_file, rd->d_name);
            stat(res, &st);
            passwd = getpwuid(st.st_uid);
            grp = getgrgid(st.st_gid);
            my_putstr(get_right(st));
            stats(st, rd, passwd, grp);
        }
    }
    closing(dir);
    return (0);
}

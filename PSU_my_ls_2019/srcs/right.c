/*
** EPITECH PROJECT, 2019
** right.c
** File description:
** Thomas Olry's right.c made the 12/30/2019
*/

#include "ls.h"

char *get_right(struct stat st)
{
    char *right = malloc(sizeof(char) * 11 + 1);

    right[0] = (st.st_mode & S_IFDIR) ? 'd' : '-';
    right[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
    right[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
    right[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
    right[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
    right[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
    right[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
    right[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
    right[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
    right[9] = (st.st_mode & S_IXOTH) ? 'x' : '-';
    right[10] = '.';
    right[11] = ' ';
    right[12] = '\0';
    return (right);
}

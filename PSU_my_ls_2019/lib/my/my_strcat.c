/*
** EPITECH PROJECT, 2019
** strcat.c
** File description:
** Day07
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *res = malloc(sizeof(char) * len_dest + len_src + 1);
    int x = 0;

    for (int i = 0; i != len_dest; i += 1, x += 1)
        res[x] = dest[i];
    for (int i = 0; src[i] != '\0'; i += 1, x += 1)
        res[x] = src[i];
    return (res);
}

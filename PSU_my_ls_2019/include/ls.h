/*
** EPITECH PROJECT, 2019
** ls.h
** File description:
** Thomas Olry's ls.h made the 12/30/2019
*/

#ifndef LS_H_
#define LS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//parsing

void simple_case(int, char **);
void flags(int, char **);

//ls_t

char *add_dir(char *);
char **put_in_tab(char *);
int ls_time(char **);
int the_date(char *);

//ls_d

int ls_d(int, char **);

//ls_r

int ls_r(char *);

//recursive

int recursive(char *);

//ls_l

int total(char *);
void stats(struct stat , struct dirent *, struct passwd *, struct group *);
void closing(DIR *);
int ls_listing(char *);

// right

char *get_right(struct stat);

//directory

int is_dir(char *);
int is_reg(char *);
int check_dir(DIR *, char *);
int read_directory(char *);
int multi_directory(int, char **);

//lib

int my_putstr(char const *);
void my_putchar(char);
int my_strcmp(char const *, char const *);
int my_strlen(char const *);
void my_put_nbr(int);
char *my_strcpy(char *, char const *);
char *my_strcat(char *, char const *);

#endif /* !LS_H_ */

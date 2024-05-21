/*
** EPITECH PROJECT, 2023
** fonction
** File description:
** fonction
*/

#ifndef MY_H
    #define MY_H
    #include "struct.h"

int my_strlen(char const *str);
char *my_strdup(char const *src);
int mini_printf(const char *format, ...);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
int my_findnbr(char const *str, int i, int neg);
int transform_into_nbr(char const *str, int start, int length, int neg);
int check(char c);

#endif

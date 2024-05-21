/*
** EPITECH PROJECT, 2023
** putstr
** File description:
** putstr
*/

#include "include/my.h"
#include "include/struct.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}

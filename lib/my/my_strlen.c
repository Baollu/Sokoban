/*
** EPITECH PROJECT, 2023
** strlen
** File description:
** strlen
*/

#include "include/my.h"
#include "include/struct.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

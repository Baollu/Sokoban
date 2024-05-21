/*
** EPITECH PROJECT, 2024
** str
** File description:
** toword
*/

#include "include/my_lib.h"
#include <stdlib.h>

int is_alpha_num(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    if (c >= 65 && c <= 90)
        return 1;
    if (c >= 97 && c <= 122)
        return 1;
    return 0;
}

int get_len(char const *str, int nbr)
{
    int i = 0;

    for (i = nbr; is_alpha_num(str[i]); i++);
    return i;
}

int get_nbr_word(char const *str)
{
    int i = 0;
    int nbr_word = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (is_alpha_num(str[i]) == 1 && is_alpha_num(str[i + 1]) == 0){
            nbr_word++;
        }
    }
    return nbr_word;
}

int skip_non_alphanum(char const *str, int z)
{
    int i = 0;

    for (i = z; is_alpha_num(str[i]) == 0; i++);
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    int nb_c = 0;
    int z = 0;
    int nbr_word = get_nbr_word(str);
    char **array = malloc(sizeof(char *) * (nbr_word + 1));

    for (i = 0; i != nbr_word; i++){
        nb_c = get_len(str, z);
        array[i] = malloc(sizeof(char) * nb_c + 1);
        for (j = 0; is_alpha_num(str[z]) == 1; j++){
            array[i][j] = str[z];
            z++;
        }
        z = skip_non_alphanum(str, z);
    }
    array[i] = NULL;
    return array;
}

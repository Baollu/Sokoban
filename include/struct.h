/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct
*/

#ifndef SOKOBAN
    #define SOKOBAN

struct sokoban_s {
    char **array;
    char **map_base;
    int px;
    int py;
    int x;
    int y;
    int nbr;
    int nbr_init;
};

#endif

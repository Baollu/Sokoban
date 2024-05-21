/*
** EPITECH PROJECT, 2023
** control
** File description:
** player
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"
#include <ncurses.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

void move_left(struct sokoban_s *sokoban)
{
    sokoban->array[sokoban->py][sokoban->px - 1] = 'P';
    sokoban->array[sokoban->py][sokoban->px] = ' ';
    if (sokoban->map_base[sokoban->py][sokoban->px] == 'O')
        sokoban->array[sokoban->py][sokoban->px] = 'O';
    sokoban->px -= 1;
}

void move_right(struct sokoban_s *sokoban)
{
    sokoban->array[sokoban->py][sokoban->px + 1] = 'P';
    sokoban->array[sokoban->py][sokoban->px] = ' ';
    if (sokoban->map_base[sokoban->py][sokoban->px] == 'O')
        sokoban->array[sokoban->py][sokoban->px] = 'O';
    sokoban->px += 1;
}

void condition_left(struct sokoban_s *sokoban)
{
    if (sokoban->array[sokoban->py][sokoban->px - 1] == 'X' &&
        sokoban->array[sokoban->py][sokoban->px - 2] != 'X' &&
        sokoban->array[sokoban->py][sokoban->px - 2] != '#'){
        sokoban->array[sokoban->py][sokoban->px] = ' ';
        sokoban->array[sokoban->py][sokoban->px - 2] = 'X';
        sokoban->array[sokoban->py][sokoban->px - 1] = 'P';
        sokoban->px -= 1;
    }
    if (sokoban->array[sokoban->py][sokoban->px - 1] != 'X')
        move_left(sokoban);
}

void condition_right(struct sokoban_s *sokoban)
{
    if (sokoban->array[sokoban->py][sokoban->px + 1] == 'X' &&
        sokoban->array[sokoban->py][sokoban->px + 2] != 'X' &&
        sokoban->array[sokoban->py][sokoban->px + 2] != '#'){
        sokoban->array[sokoban->py][sokoban->px] = ' ';
        sokoban->array[sokoban->py][sokoban->px + 2] = 'X';
        sokoban->array[sokoban->py][sokoban->px + 1] = 'P';
        sokoban->px += 1;
    }
    if (sokoban->array[sokoban->py][sokoban->px + 1] != 'X')
        move_right(sokoban);
}

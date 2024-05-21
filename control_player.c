/*
** EPITECH PROJECT, 2023
** player
** File description:
** player
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

void move_up(struct sokoban_s *sokoban)
{
    sokoban->array[sokoban->py - 1][sokoban->px] = 'P';
    sokoban->array[sokoban->py][sokoban->px] = ' ';
    if (sokoban->map_base[sokoban->py][sokoban->px] == 'O')
        sokoban->array[sokoban->py][sokoban->px] = 'O';
    sokoban->py -= 1;
}

void move_down(struct sokoban_s *sokoban)
{
    sokoban->array[sokoban->py + 1][sokoban->px] = 'P';
    sokoban->array[sokoban->py][sokoban->px] = ' ';
    if (sokoban->map_base[sokoban->py][sokoban->px] == 'O')
        sokoban->array[sokoban->py][sokoban->px] = 'O';
    sokoban->py += 1;
}

void condition_down(struct sokoban_s *sokoban)
{
    if (sokoban->array[sokoban->py + 1][sokoban->px] == 'X' &&
        sokoban->array[sokoban->py + 2][sokoban->px] != 'X' &&
        sokoban->array[sokoban->py + 2][sokoban->px] != '#'){
        if (sokoban->map_base[sokoban->py][sokoban->px] == 'O')
            sokoban->array[sokoban->py][sokoban->px] = 'O';
        else {
        sokoban->array[sokoban->py][sokoban->px] = ' ';
        }
        sokoban->array[sokoban->py + 2][sokoban->px] = 'X';
        sokoban->array[sokoban->py + 1][sokoban->px] = 'P';
        sokoban->py += 1;
    }
    if (sokoban->array[sokoban->py + 1][sokoban->px] != 'X')
        move_down(sokoban);
}

void condition_up(struct sokoban_s *sokoban)
{
    if (sokoban->array[sokoban->py - 1][sokoban->px] == 'X' &&
        sokoban->array[sokoban->py - 2][sokoban->px] != 'X' &&
        sokoban->array[sokoban->py - 2][sokoban->px] != '#'){
        sokoban->array[sokoban->py][sokoban->px] = ' ';
        sokoban->array[sokoban->py - 2][sokoban->px] = 'X';
        sokoban->array[sokoban->py - 1][sokoban->px] = 'P';
        sokoban->py -= 1;
    }
    if (sokoban->array[sokoban->py - 1][sokoban->px] != 'X')
        move_up(sokoban);
}

char **control_player(struct sokoban_s *sokoban, int key)
{
    if (key == KEY_DOWN)
        if (sokoban->array[sokoban->py + 1][sokoban->px] != '#')
            condition_down(sokoban);
    if (key == KEY_UP)
        if (sokoban->array[sokoban->py - 1][sokoban->px] != '#')
            condition_up(sokoban);
    if (key == KEY_LEFT)
        if (sokoban->array[sokoban->py][sokoban->px - 1] != '#')
            condition_left(sokoban);
    if (key == KEY_RIGHT)
        if (sokoban->array[sokoban->py][sokoban->px + 1] != '#')
            condition_right(sokoban);
    refresh();
    return sokoban->array;
}

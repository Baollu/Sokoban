/*
** EPITECH PROJECT, 2023
** reset
** File description:
** reset
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"
#include <stdlib.h>
#include <ncurses.h>

void reset_map(struct sokoban_s *sokoban, int key)
{
    int i = 0;

    if (key == 32){
        for (i = 0; sokoban->array[i] != NULL; i++)
            mvprintw(LINES / 2 + i, (COLS / 2), "%s\n", sokoban->map_base[i]);
        sokoban->array[i] = sokoban->map_base[i];
    }
}

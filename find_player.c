/*
** EPITECH PROJECT, 2023
** move
** File description:
** move
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"
#include <stdlib.h>
#include <ncurses.h>

void find_player(struct sokoban_s *sokoban, int x, int y)
{
    int i = 0;
    int j = 0;

    for (i = 0; i != y; i++){
        j = 0;
        while (j != x && sokoban->array[i][j] != 'P')
            j++;
        if (sokoban->array[i][j] == 'P'){
            sokoban->px = j;
            sokoban->py = i;
            return;
        }
    }
}

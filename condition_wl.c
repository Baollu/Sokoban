/*
** EPITECH PROJECT, 2023
** condition
** File description:
** win
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"

void nbr_o(struct sokoban_s *sokoban, int i, int j)
{
    if (sokoban->array[i][j] == 'O')
        sokoban->nbr++;
}

int condition_win(struct sokoban_s *sokoban)
{
    int i = 0;
    int j = 0;

    sokoban->nbr = 0;
    for (i = 0; i != sokoban->y; i++){
        for (j = 0; j != sokoban->x; j++)
            nbr_o(sokoban, i, j);
    }
    if (sokoban->map_base[sokoban->py][sokoban->px] != 'O'){
        if (sokoban->nbr == 0)
            return 1;
    }
    return 0;
}

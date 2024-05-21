/*
** EPITECH PROJECT, 2023
** game
** File description:
** game
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"
#include <stdlib.h>
#include <ncurses.h>

void play(char const *pathname)
{
    struct sokoban_s *sokoban = malloc(sizeof(struct sokoban_s));
    int key = 0;

    sokoban = generate_map(pathname);
    initscr();
    for (int i = 0; sokoban->array[i] != NULL; i++)
    mvprintw(LINES / 2 + i, (COLS / 2), "%s\n", sokoban->array[i]);
    keypad(stdscr, TRUE);
    while (key != 113){
        key = getch();
        sokoban->array = control_player(sokoban, key);
        for (int i = 0; sokoban->array[i] != NULL; i++)
            mvprintw(LINES / 2 + i, (COLS / 2), "%s\n", sokoban->array[i]);
        if (condition_win(sokoban))
            break;
    }
    endwin();
    free(sokoban);
}

/*
** EPITECH PROJECT, 2023
** map
** File description:
** map
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

void copy_map(struct sokoban_s *sokoban, int x, int y)
{
    int i = 0;
    int j = 0;

    sokoban->map_base = malloc(sizeof(char *) * (y + 1));
    while (i != y){
        sokoban->map_base[i] = malloc(sizeof(char) * (x + 1));
        while (j != x){
            sokoban->map_base[i][j] = sokoban->array[i][j];
            j++;
        }
        sokoban->map_base[i][j] = '\0';
        j = 0;
        i++;
    }
}

struct sokoban_s *conversion(char const *filepath, int x, int y)
{
    struct sokoban_s *sokoban = malloc(sizeof(struct sokoban_s));
    int fd;
    int i = 0;

    fd = open(filepath, O_RDONLY);
    sokoban->array = malloc(sizeof(char *) * (y + 1));
    for (i = 0; i != y; i++){
        sokoban->array[i] = malloc(sizeof(char) * (x + 1));
        read(fd, sokoban->array[i], x + 1);
        sokoban->array[i][x] = '\0';
    }
    find_player(sokoban, x, y);
    sokoban->array[y] = NULL;
    sokoban->x = x;
    sokoban->y = y;
    copy_map(sokoban, x, y);
    close(fd);
    return sokoban;
}

struct sokoban_s *generate_map(char const *filepath)
{
    int fd;
    char buffer[1] = "";
    int i = 0;
    int x = 0;
    int y = 0;

    fd = open(filepath, O_RDONLY);
    for (; buffer[0] != '\n'; i++)
        read(fd, buffer, 1);
    x = i;
    for (; read(fd, buffer, 1) != 0; i++);
    y = i / x;
    x -= 1;
    close(fd);
    return conversion(filepath, x, y);
}

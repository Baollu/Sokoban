/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    char const *filepath = argv[1];
    int fd = open(filepath, O_RDONLY);

    if (argc != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h'){
        rules();
        return 0;
    }
    if (fd == -1)
        return 84;
    if (stored_buf(filepath) == 1)
        return 84;
    play(argv[1]);
    return 0;
}

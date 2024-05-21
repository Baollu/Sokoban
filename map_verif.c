/*
** EPITECH PROJECT, 2024
** map
** File description:
** verif
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/p_my.h"
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int nb_p(char *buffer)
{
    int p = 0;

    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == 'P'){
            p++;
        }
        if (p >= 2)
            return 1;
    }
    return 0;
}

int valid_map(char *buffer)
{
    for (int j = 0; buffer[j] != '\0'; j++){
        if (buffer[j] != '#' && buffer[j] != ' ' && buffer[j] != 'P'
            && buffer[j] != 'X' && buffer[j] != 'O' && buffer[j] != '\0'
            && buffer[j] != '\n')
            return 1;
    }
    if (nb_p(buffer) == 1)
        return 1;
    return 0;
}

int stored_buf(char const *filepath)
{
    struct stat info;
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);

    stat(filepath, &info);
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    read(fd, buffer, info.st_size);
    buffer[info.st_size] = '\0';
    if (valid_map(buffer) == 1)
        return 1;
    return 0;
}

/*
** EPITECH PROJECT, 2023
** str
** File description:
** struct
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct stuff_s {
    int id;
    char *categorie;
    char *name;
    struct stuff_s *next;
} stuff_t;

#endif

/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#ifndef P_MY_H
    #define P_MY_H
    #include "struct.h"

void nbr_o(struct sokoban_s *sokoban, int i, int j);
int condition_win(struct sokoban_s *sokoban);
void move_left(struct sokoban_s *sokoban);
void move_right(struct sokoban_s *sokoban);
void condition_left(struct sokoban_s *sokoban);
void condition_right(struct sokoban_s *sokoban);
void move_up(struct sokoban_s *sokoban);
void move_down(struct sokoban_s *sokoban);
void condition_down(struct sokoban_s *sokoban);
void condition_up(struct sokoban_s *sokoban);
char **control_player(struct sokoban_s *sokoban, int key);
void find_player(struct sokoban_s *sokoban, int x, int y);
void copy_map(struct sokoban_s *sokoban, int x, int y);
struct sokoban_s *conversion(char const *filepath, int x, int y);
struct sokoban_s *generate_map(char const *filepath);
void play(char const *pathname);
void reset_map(struct sokoban_s *sokoban, int key);
void rules(void);
int nb_p(char *buffer);
int valid_map(char *buffer);
int stored_buf(char const *filepath);

#endif

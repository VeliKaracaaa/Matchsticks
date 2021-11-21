/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MY_H_
#define MY_H_

typedef struct my_struct_s
{
    int nb_line;
    int nb_column;
    char **game_board;
    int nb_stick;
    int nb_line_player;
    int nb_match_player;
    int max_stick_match;
    int nb_line_ia;
    int nb_match_ia;
    int nb_stick_line;
} my_struct_t;

int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);

int error(int ac, char **av);

char *space_board(char *str, int space, int *count_column);
char *stick_board(char *str, int stick, int *count_column);
char **malloc_game_board(char **av, my_struct_t *my_struct);
void print_game_board(my_struct_t *my_struct);

void calculation_stick(my_struct_t *my_struct);
int check_if_character(char *lineptr);
int game_loop_player_line(my_struct_t *my_struct);
int game_loop_player_match(my_struct_t *my_struct);
int check_info_line(my_struct_t *my_struct);
int check_info_match(my_struct_t *my_struct);
int count_stick_line(my_struct_t *my_struct);
void print_ia(my_struct_t *my_struct);

int game_loop(my_struct_t *my_struct);
void game_board_player(my_struct_t *my_struct);
void game_board_ia(my_struct_t *my_struct);
int game_board_ia_gestion_nb_stick_rest(my_struct_t *my_struct);
void game_board_gestion_stcik(my_struct_t *my_struct);

#endif /* !MY_H_ */

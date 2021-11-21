/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "../include/my.h"

int game_loop_player_line(my_struct_t *my_struct)
{
    char *lineptr = NULL;
    int check = 0;
    size_t n = 0;

    while (1) {
        my_putstr("Line: ");
        lineptr = NULL;
        getline(&lineptr, &n, stdin);
        if (*lineptr == 0)
            return (-1);
        if (check_if_character(lineptr) == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            continue;
        }
        my_struct->nb_line_player = my_getnbr(lineptr);
        if (my_struct->nb_line_player == 0) {
            my_putstr("Error: this line is out of range\n");
            continue;
        }
        if (check_info_line(my_struct) == 0)
            continue;
        check = game_loop_player_match(my_struct);
        if (check == 1)
            continue;
        if (check == -1)
            return (-1);
        return (0);
    }
}

int game_loop_player_match(my_struct_t *my_struct)
{
    char *lineptr = NULL;
    size_t n = 0;

    while (1) {
        my_putstr("Matches: ");
        getline(&lineptr, &n, stdin);
        if (*lineptr == 0)
            return (-1);
        if (check_if_character(lineptr) == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
        my_struct->nb_match_player = my_getnbr(lineptr);
        if (my_struct->nb_match_player == 0) {
            my_putstr("Error: you have to remove at least one match\n");
            return (1);
        }
        if (check_info_match(my_struct) == 1)
            return (1);
        count_stick_line(my_struct);
        if (my_struct->nb_match_player > my_struct->nb_stick_line) {
            my_putstr("Error: not enough matches on this line\n");
            return (1);
        }
        return (0);
    }
}

void game_board_player(my_struct_t *my_struct)
{
    int i;
    int tmp = 1;

    for (i = my_struct->nb_column; my_struct->game_board[my_struct->nb_line_player - 1][i] != '|'; i--);
    for (; tmp <= my_struct->nb_match_player; tmp++) {
        my_struct->game_board[my_struct->nb_line_player - 1][i] = ' ';
        i--;
    }
}
/*
** EPITECH PROJECT, 2020
** game_gestion
** File description:
** game_getsion
*/

#include "../include/my.h"

void calculation_stick(my_struct_t *my_struct)
{
    int nb_stick_online = 1;
    my_struct->nb_stick = 1;

    for (int i = 0; i != my_struct->nb_line - 2; i++) {
        nb_stick_online = nb_stick_online + 2;
        my_struct->nb_stick = my_struct->nb_stick + nb_stick_online;
    }
}

int check_if_character(char *lineptr)
{
    for (int i = 0; lineptr[i] != '\n'; i++) {
        if (lineptr[i] < '0' || lineptr[i] > '9') {
            return (1);
        }
    }
    return (0);
}

int check_info_line(my_struct_t *my_struct)
{
    if (my_struct->nb_line_player > my_struct->nb_line - 1) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    return (1);
}

int check_info_match(my_struct_t *my_struct)
{
    if (my_struct->nb_match_player > my_struct->max_stick_match) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(my_struct->max_stick_match);
        my_putstr(" matches per turn\n");
        return (1);
    }
    return (0);
}

int count_stick_line(my_struct_t *my_struct)
{
    my_struct->nb_stick_line = 0;
    for (int i = 0; my_struct->game_board[my_struct->nb_line_player - 1][i] != '\0'; i++) {
        if (my_struct->game_board[my_struct->nb_line_player - 1][i] == '|')
            my_struct->nb_stick_line++;
    }
    return (0);
}
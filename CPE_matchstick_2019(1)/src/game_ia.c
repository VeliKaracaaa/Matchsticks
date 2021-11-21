/*
** EPITECH PROJECT, 2020
** game
** File description:
** game
*/

#include "../include/my.h"

void print_ia(my_struct_t *my_struct)
{
        my_putstr("\nAI's turn...\n");
        my_putstr("AI removed ");
        my_put_nbr(my_struct->nb_match_ia);
        my_putstr(" match(es) from line ");
        my_put_nbr(my_struct->nb_line_ia);
        my_putstr("\n");
}

void game_board_ia(my_struct_t *my_struct)
{
    do {
        my_struct->nb_line_ia = (rand() % (my_struct->nb_line - 1)) + 1;
        my_struct->nb_match_ia = (rand() % (my_struct->max_stick_match)) + 1;
    } while (game_board_ia_gestion_nb_stick_rest(my_struct));
    game_board_gestion_stcik(my_struct);
}

int game_board_ia_gestion_nb_stick_rest(my_struct_t *my_struct)
{
    int tmp_stick = 0;

    for (int i = 0; my_struct->game_board[my_struct->nb_line_ia - 1][i] != '\0'; i++) {
        if (my_struct->game_board[my_struct->nb_line_ia - 1][i] == '|')
            tmp_stick++;
    }
    if (my_struct->nb_match_ia > tmp_stick) {
        return (1);
    }
    return (0);
}

void game_board_gestion_stcik(my_struct_t *my_struct)
{
    int i;
    int tmp = 1;

    for (i = my_struct->nb_column - 1; my_struct->game_board[my_struct->nb_line_ia - 1][i] != '|'; i--);
    for (; tmp <= my_struct->nb_match_ia; tmp++) {
        my_struct->game_board[my_struct->nb_line_ia - 1][i] = ' ';
        i--;
    }
}
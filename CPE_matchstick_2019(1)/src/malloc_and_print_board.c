/*
** EPITECH PROJECT, 2020
** malloc_and_print_board
** File description:
** malloc_and_print_board
*/

#include "../include/my.h"

char *space_board(char *str, int space, int *count_column)
{
    for (int i = 0; i != space; i++) {
        str[*count_column] = ' ';
        *count_column = *count_column + 1;
    }
    return (str);
}

char *stick_board(char *str, int stick, int *count_column)
{
    for (int i = 0; i != stick; i++) {
        str[*count_column] = '|';
        *count_column = *count_column + 1;
    }
    return (str);
}

char **malloc_game_board(char **av, my_struct_t *my_struct)
{
    int space = my_getnbr(av[1]);
    int stick = 1;
    int count_column = 0;
    char **game_board = malloc(sizeof(char *) * (my_getnbr(av[1]) + 2));

    space = (space + space - 1) / 2;
    my_struct->nb_line = my_getnbr(av[1]) + 1;
    my_struct->nb_column = my_getnbr(av[1]) * 2 - 1;
    for (int i = 0; i != my_struct->nb_line - 1; i++)
        game_board[i] = malloc(sizeof(char) * (my_struct->nb_column + 1));
    for (int j = 0; j != my_struct->nb_line - 1; j++) {
        game_board[j] = space_board(game_board[j], space, &count_column);
        game_board[j] = stick_board(game_board[j], stick, &count_column);
        game_board[j] = space_board(game_board[j], space, &count_column);
        game_board[j][count_column] = '\0';
        count_column = 0;
        stick = stick + 2;
        space = space - 1;
    }
    return (game_board);
}

void print_game_board(my_struct_t *my_struct)
{
    for (int i = 0; i <= my_struct->nb_column + 1; i++)
        my_putchar('*');
    my_putstr("\n");
    for (int k = 0; k != my_struct->nb_line - 1; k++) {
        my_putchar('*');
        my_putstr(my_struct->game_board[k]);
        my_putstr("*\n");
    }
    for (int i = 0; i <= my_struct->nb_column + 1; i++)
        my_putchar('*');
    my_putstr("\n");
}
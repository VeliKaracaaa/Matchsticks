/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"
#include <stdio.h>

int error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) > 99)
        return (84);
    if (my_getnbr(av[2]) == 0)
        return (84);
    if (my_getnbr(av[2]) < 1)
        return (84);
    return (0);
}

int game_loop(my_struct_t *my_struct)
{
    print_game_board(my_struct);
    while (my_struct->nb_stick != 0) {
        my_putstr("\nYour turn:\n");
        if (game_loop_player_line(my_struct) == -1)
            return (3);
        my_struct->nb_stick = my_struct->nb_stick - my_struct->nb_match_player;
        my_putstr("Player removed ");
        my_put_nbr(my_struct->nb_match_player);
        my_putstr(" match(es) from line ");
        my_put_nbr(my_struct->nb_line_player);
        my_putstr("\n");
        game_board_player(my_struct);
        print_game_board(my_struct);
        if (my_struct->nb_stick == 0)
            return (1);
        game_board_ia(my_struct);
        print_ia(my_struct);
        print_game_board(my_struct);
        my_struct->nb_stick = my_struct->nb_stick - my_struct->nb_match_ia;
    }
    return (0);
}

int main(int ac, char **av)
{
    my_struct_t my_struct;
    int check = 0;

    if (error(ac, av) == 84)
        return (84);
    my_struct.game_board = malloc_game_board(av, &my_struct);
    calculation_stick(&my_struct);
    my_struct.max_stick_match = my_getnbr(av[2]);
    check = game_loop(&my_struct);
    if (check == 1) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    else if (check == 3)
        return (0);
    else {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
}
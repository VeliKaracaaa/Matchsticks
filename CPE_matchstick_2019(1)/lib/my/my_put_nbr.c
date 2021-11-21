/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** task 04
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48);
    else if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        my_put_nbr(nb);
    }
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (nb);
}

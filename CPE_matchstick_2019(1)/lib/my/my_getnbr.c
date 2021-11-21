/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int result = 0;
    int neg = 0;

    if (str[i] == '-' && str[i + 1] >= 48 && str[i + 1] <= 57) {
        neg = 1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        result = result * 10;
        result = result + str[i] - 48;
        i++;
    }
    if (neg == 1)
        result = result * (-1);
    return (result);
}

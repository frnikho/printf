/*
** EPITECH PROJECT, 2019
** my_printf_d_flags
** File description:
** printf d flags
*/

#include "my.h"
#include "myprintf.h"

void my_printf_show_d(char *str, int index, int nbr, int operator)
{
    int d_nbr = my_printf_nbr_params(str, index);
    int length = get_int_length(nbr) - 1;

    if (operator == -1) {
        my_put_nbr(nbr);
        operator *= -1;
    }
    for (int i = 0; i < d_nbr - operator; i++) {
        if (length - i <= 0 )
            my_putchar(32);
    }
    if (operator == 1) {
        my_putchar('+');
        my_put_nbr(nbr);
    } else if (operator == 0) {
        my_put_nbr(nbr);
    }
}

int my_printf_nbr_params(char *str, int index)
{
    return my_getnbr_index(str, index);
}

void my_printf_d_flags(char *str, int index, int nbr)
{
    if (str[index] == '-')
        my_printf_show_d(str, index+1, nbr, -1);
    if (str[index] == '+')
        my_printf_show_d(str, index+1, nbr, +1);
    if (my_isnum(str[index])) {
        my_printf_show_d(str, index, nbr, 0);
    }
}
/*
** EPITECH PROJECT, 2019
** display_printf
** File description:
** display function for printf
*/

#include "my.h"
#include "myprintf.h"

void display_unsigned_int(va_list ap)
{
    int nb = va_arg(ap, unsigned int);
    if (nb > 0)
        my_put_nbr(nb);
    else
        my_putstr("error, not a unsigned int");
}

void display_s_my_printf(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 32 || str[i] == 127) {
            char *octal = my_putnbr_base(str[i], "01234567");
            int length = my_strlen(octal);
            if (length == 1)
                my_putstr("0\\00");
            if (length == 2)
                my_putstr("0\\0");
            my_putstr(octal);
        } else {
            my_putchar(str[i]);
        }
    }
}
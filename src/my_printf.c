/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** printf function
*/

#include "my.h"
#include "myprintf.h"

void display_S_my_printf(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if(str[i] < 32 || str[i] == 127) {
            char *octal = my_putnbr_base(str[i], "01234567");
            int length = my_strlen(octal);
            if (length == 1)
                my_putstr("\\00");
            if (length == 2)
                my_putstr("\\0");
            my_putstr(octal);
        } else {
            my_putchar(str[i]);
        }
    }
}

int is_my_printf_value(char const *str, int index)
{
    char tabs[9] = {'c', 's', 'd', 'o', 'x', 'b', 'p', 'P', 'S'};

    if (str[index] == '%') {
        if (str[index + 1] == 'l' && str[index + 2] == 'f')
            return (2);
        for (int i = 0; i <= 10; i++) {
            if (str[index + 1] == tabs[i]) {
                return (1);
            }
        }
    } else {
        return (0);
    }
}

void my_printf_check_type(char const *str, int index, va_list ap)
{
    if (str[index + 1] == 's')
        my_putstr(va_arg(ap, char*));
    if (str[index + 1] == 'd' || str[index + 1] == 'i')
        my_put_nbr(va_arg(ap, int));
    if (str[index + 1] == 'c')
        my_putchar(va_arg(ap, int));
    if (str[index + 1] == 'x')
        my_putstr(my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF"));
    if (str[index + 1] == 'b')
        my_putstr(my_putnbr_base(va_arg(ap, int), "01"));
    if (str[index + 1] == 'S')
        display_S_my_printf(va_arg(ap, char*));
    if (str[index + 1] == 'P')
        my_putstr(my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF"));
    if (str[index + 1] == 'p') {
        my_putstr("0x");
        my_putstr(my_putnbr_base(va_arg(ap, int), "0123456789abcdef"));
    }
    if (str[index + 1] == 'u')
}

void my_printf(char const *str, ...)
{
    va_list ap;
    va_start(ap, 0);

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '%') {
            int nb = is_my_printf_value(str, i);
            if (nb != 0)
                my_printf_check_type(str, i, ap);
            i += nb;
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(ap);
}

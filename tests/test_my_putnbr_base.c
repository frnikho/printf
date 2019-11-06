/*
** EPITECH PROJECT, 2019
** test_my_putnbr_base.c
** File description:
** unit tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_putnbr_base, convert_into_hexadecimal)
{
    int nbr = 495;
    char *hexa = "1EF";
    char *base = "0123456789ABCDEF";
    char *result = my_putnbr_base(nbr, base);
    cr_expect_str_eq(result, hexa);
}

Test(my_putnbr_base, convert_into_hexadecimal_simple)
{
    int nbr = 52401;
    char *hexa = "CCB1";
    char *base = "0123456789ABCDEF";
    char *result = my_putnbr_base(nbr, base);
    cr_expect_str_eq(result, hexa);
}

Test(my_putnbr_base, convert_into_octal)
{
    int nbr = 495;
    char *octal = "757";
    char *base = "01234567";
    char *result = my_putnbr_base(nbr, base);
    cr_expect_str_eq(result, octal);
}
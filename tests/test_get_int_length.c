/*
** EPITECH PROJECT, 2019
** test_get_int_length.c
** File description:
** unit tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(get_int_length, get_length)
{
    int nbr = 120;
    int res = get_int_length(nbr);
    cr_expect_eq(res, 3);
}
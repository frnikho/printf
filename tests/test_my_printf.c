/*
** EPITECH PROJECT, 2019
** test printf function
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "myprintf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, string, .init=redirect_all_std)
{
    char *world = "World";
    my_printf("Hello %s", world);
    cr_assert_stdout_eq_str("Hello World");
}

Test(my_printf, just_one_string, .init=redirect_all_std)
{
    my_printf("Hello World !");
    cr_assert_stdout_eq_str("Hello World !");
}

Test(my_printf, one_flag_without_arg, .init=redirect_all_std)
{
    my_printf("Hello World %d");
    cr_assert_stdout_eq_str("Hello World 0");
}

Test(my_printf, integer, .init=redirect_all_std)
{
    int age = 19;
    my_printf("I'm %d", age);
    cr_assert_stdout_eq_str("I'm 19");
}

Test(my_printf, character, .init=redirect_all_std)
{
    char r = 'r';
    my_printf("Hello Wo%cld", r);
    cr_assert_stdout_eq_str("Hello World");
}

Test(my_printf, char_ascii, .init=redirect_all_std)
{
    char char_ascii[5] = "toto";
    char_ascii[1] = 6;
    my_printf("%S", char_ascii);
    cr_assert_stdout_eq_str("t0\\006to");
}

Test(my_printf, modulo, .init=redirect_all_std)
{
    my_printf("Hello World %% test");
    cr_assert_stdout_eq_str("Hello World % test");
}

Test(my_printf, only_modulo, .init=redirect_all_std)
{
    my_printf("abc % test");
    cr_assert_stdout_eq_str("abc % test");
}

Test(printf, float_nbr, .init=redirect_all_std)
{
    float ab = 5012.65;
    my_printf("%f", ab);
    cr_assert_stdout_eq_str("5012.649902");
}

Test(printf, number_with_flags, .init=redirect_all_std)
{
    float ab = 5012.612619;
    my_printf("%.2f", ab);
    cr_assert_stdout_eq_str("5012.61");
}
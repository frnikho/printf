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

Test(printf, d_flags_1)
{
    int nbr = 10020;
//printf("%7d", nbr);
    //my_printf("%d", nbr);
//my_printf("\n");
}

Test(my_printf_nbr_params, number_1)
{
    char *flags = "%1d";
    int nbr = my_printf_nbr_params(flags, 1);
    cr_expect_eq(nbr, 1);
}

Test(my_printf_d_flags, nb3, .init=redirect_all_std)
{
    char *flags = "%3d";
    int nbr  = 50;
    my_printf_d_flags(flags, 1, nbr);
    cr_assert_stdout_eq_str(" 50");
}

Test(my_printf_d_flags, nb20, .init=redirect_all_std)
{
    char *flags = "%20d";
    int nbr  = 50;
    my_printf_d_flags(flags, 1, nbr);
    cr_assert_stdout_eq_str("                  50");
}


Test(my_printf_d_flags, nb_plus_20, .init=redirect_all_std)
{
    char *flags = "%+20d";
    int nbr = 50;
    my_printf_d_flags(flags, 1, nbr);
    cr_assert_stdout_eq_str("                 +50");
}

Test(my_printf, d_flags_plus, .init=redirect_all_std)
{
    int nbr = 2016;
    my_printf("%7d is the number like %x in hexa", nbr, nbr);
    cr_assert_stdout_eq_str("    2016 is the number like 7e0 in hexa");
}

Test(my_printf, d_flags_plus_2, .init=redirect_all_std)
{
    int nbr = 20;
    my_printf("%55d is the number like %x in hexa", nbr, nbr);
    cr_assert_stdout_eq_str("                                                     20 is the number like 14 in hexa");
}

Test(my_printf, error_handle_modulo_1, .init=redirect_all_std)
{
    my_printf("%%%%%%");
    cr_assert_stdout_eq_str("%%%");
}

Test(my_printf, error_handle_modulo_2, .init=redirect_all_std)
{
    my_printf("%");
    cr_assert_stdout_eq_str("%");
}
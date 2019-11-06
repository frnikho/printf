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

Test(my_print, all_tested, .init=redirect_all_std)
{
    char *world = "Hello World !";
    int nbr = -50415;
    int nb2 = 495;
    char c = 'Y';
    char toto[5] = "toto";
    toto[1] = 6;
    my_printf("%s I'm %d %cears old, %b, %x test %S, %p, %P", world, nbr, c, nbr, nb2, toto, nb2, nb2);
    cr_expect_stdout_eq_str("Hello World ! I'm -50415 Years old, 1100010011101111, 1EF test t0\\006to, 0x1ef, 1EF");
}

/*

Test(display_S_my_printf, display)
{
    char test[5] = "toto";
    test[1] = 6;
    display_S_my_printf(test);
}

 */
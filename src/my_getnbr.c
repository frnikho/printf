/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** convert a string into a number
*/

#include "my.h"

int my_getnbr(char const *str)
{
   int length = my_strlen(str);
   int result = 0;

   for (int i = length; i != 0; i--) {
        int a = (str[i] - 48) * (length * 10);
        result += a;
        length--;
   }

   return (result);
}
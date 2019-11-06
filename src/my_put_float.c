/*
** EPITECH PROJECT, 2019
** my_put_float
** File description:
** show float number
*/

void my_putchar(char c);

void my_put_float(float nbr)
{
    if (nbr > -2147483647 && nbr < 2147483647) {
        if (nbr >= 10) {
            my_put_nbrr(nbr / 10);
            my_put_nbrr(nbr % 10);
        }
        if (nbr < 10 && nbr >= 0) {
            my_putchar('0' + nbr);
        }
        if (nbr < 0) {
            my_putchar('-');
            my_put_nbrr(nbr * -1);
        }
    }
}
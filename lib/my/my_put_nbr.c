/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-alexis.drago-beltran
** File description:
** my_put_nbr.c
*/

#include "../../include/my.h"

int my_put_nbr(int n)
{
    if (n == -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10)
        my_put_nbr(n / 10);
    my_putchar(n % 10 + '0');
    return 0;
}

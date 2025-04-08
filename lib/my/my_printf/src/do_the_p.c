/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-alexis.drago-beltran
** File description:
** do_the_p.c
*/

#include "../../../../include/my.h"
#include "../../../../include/my_printf.h"
#include <stdlib.h>
#include <unistd.h>

int do_the_p(long long n)
{
    if ((void *) n == NULL)
        my_putstr("(nil)");
    else {
        my_putstr("0x");
        my_putnbr_base_long(n, "0123456789abcdef");
    }
    return (void *) n == NULL ? 5 : my_intlen(n) + 2;
}

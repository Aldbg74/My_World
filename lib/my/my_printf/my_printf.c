/*
** EPITECH PROJECT, 2024
** My_Printf
** File description:
** my_printf.c
*/

#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../../include/my_printf.h"

static int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

static int my_put_nbr(int nb)
{
    int test = 1;
    int n = nb;
    int count = 0;

    if (n < 0) {
        my_putchar('-');
        count += 1 + my_put_nbr(nb * -1);
        return count;
    }
    while (n > 9) {
        n = n / 10;
        test = test * 10;
    }
    while (test >= 1) {
        my_putchar(((nb / test) % 10) + '0');
        count++;
        test = test / 10;
    }
    return count;
}

static int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        write(1, & str[i], 1);
    }
    return (i);
}

int do_the_stuff2(char indic, va_list params)
{
    int count = 0;
    int ap;
    int specifier;
    int nbr;

    if (indic == 'p')
        count += do_the_p(va_arg(params, long long));
    return count;
}

int do_the_stuff(char indic, va_list params)
{
    int count = 0;
    int ap;
    int specifier;
    int nbr;

    if (indic == 'd' || indic == 'i')
        count += my_put_nbr(va_arg(params, int));
    if (indic == 's')
        count += my_putstr(va_arg(params, char *));
    if (indic == 'c')
        count += my_putchar(va_arg(params, int));
    if (indic == '%')
        count += my_putchar('%');
    if (indic == 'n')
        return count;
    if (indic == 'o')
        count += do_the_o(va_arg(params, unsigned int));
    else
        do_the_stuff2(indic, params);
    return count;
}

int my_printf(const char *format, ...)
{
    va_list params;
    int count = 0;
    int i = 0;

    va_start(params, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && what_indic(format + i) != '\0') {
            count += do_the_stuff(what_indic(format + i), params);
            i++;
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(params);
    return count - 1;
}

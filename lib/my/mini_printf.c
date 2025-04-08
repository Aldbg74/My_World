/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-miniprintf-alexis.drago-beltran
** File description:
** mini_printf.c
*/

#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

int giga_chiasse(char c)
{
    if (c == 'd')
        return 0;
    if (c == 's')
        return 0;
    if (c == 'i')
        return 0;
    if (c == 'c')
        return 0;
    if (c == '%')
        return 0;
    return 1;
}

int do_the_stuff(const char *format, int i, va_list params)
{
    int count = 0;

    if (format[i] == 'd') {
        count += my_put_nbr(va_arg(params, int));
    }
    if (format[i] == 'i') {
        count += my_put_nbr(va_arg(params, int));
    }
    if (format[i] == 's') {
        count += my_putstr(va_arg(params, char *));
    }
    if (format[i] == 'c') {
        count += my_putchar(va_arg(params, int));
    }
    if (format[i] == '%') {
        count += my_putchar('%');
    }
    return count;
}

int mini_printf(const char *format, ...)
{
    va_list params;
    int count = 0;
    int i = 0;

    va_start(params, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && giga_chiasse(format[i + 1]) == 0) {
            i++;
            count += do_the_stuff(format, i, params);
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(params);
    return count - 1;
}

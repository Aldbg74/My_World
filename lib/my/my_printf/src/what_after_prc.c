/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-alexis.drago-beltran
** File description:
** what_after_prc.c
*/

#include "../../../../include/my.h"
#include "../../../../include/my_printf.h"

char what_indic(char *str_from_prc)
{
    int i = 0;

    if (str_from_prc[1] == '%')
        return '%';
    for (i = 1; str_from_prc[i] != '\0'; i++) {
        if (str_from_prc[i] == 'd' || str_from_prc[i] == 'i' ||
            str_from_prc[i] == 'o' || str_from_prc[i] == 'u' ||
            str_from_prc[i] == 'x' || str_from_prc[i] == 'X' ||
            str_from_prc[i] == 'e' || str_from_prc[i] == 'E' ||
            str_from_prc[i] == 'f' || str_from_prc[i] == 'F' ||
            str_from_prc[i] == 'g' || str_from_prc[i] == 'G' ||
            str_from_prc[i] == 'a' || str_from_prc[i] == 'A' ||
            str_from_prc[i] == 'c' || str_from_prc[i] == 's' ||
            str_from_prc[i] == 'S' || str_from_prc[i] == 'p')
            return str_from_prc[i];
        if (str_from_prc[i] == '%')
            return '\0';
    }
    return '\0';
}

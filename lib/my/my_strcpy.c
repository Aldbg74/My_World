/*
** EPITECH PROJECT, 2023
** Delivery
** File description:
** my_strcpy.c
*/
#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    char *orgidest = dest;

    while (*src != 0) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return orgidest;
}

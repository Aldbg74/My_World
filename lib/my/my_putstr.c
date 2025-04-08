/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-alexis.drago-beltran
** File description:
** my_putstr.c
*/
#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        write(1, & str[i], 1);
    }
    return (0);
}

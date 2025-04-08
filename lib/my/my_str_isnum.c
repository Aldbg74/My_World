/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-alexis.drago-beltran
** File description:
** my_str_isnum.c
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    int i = 0;
    char numeber;

    for (i = 0; i != '\0'; i++) {
        if (str[i] >= 0 && str[i] <= 9) {
            return 1;
        } else
            return 0;
    }
}

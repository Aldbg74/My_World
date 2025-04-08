/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-alexis.drago-beltran
** File description:
** my_gentbr.c
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int isnum = 0;
    int isnegat = 0;
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isnum(str[i]) && isnum == 1)
            break;
        if (str[i] == 45 && str[i + 1] >= 48 && str[i + 1] <= 57) {
            isnegat = 1;
            i++;
        }
        isnum = 1;
        num = num * 10 + (str[i] - '0');
        if ((2147483647 - num) < 0)
            num = 0;
    }
    return isnegat == 1 ? num * -1 : num;
}

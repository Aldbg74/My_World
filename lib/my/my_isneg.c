/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-alexis.drago-beltran
** File description:
** my_isneg.c
*/
#include "../../include/my.h"

int my_isneg(int nb)
{
    if (nb < 0) {
        write(1, "N", 1);
    } else {
        write(1, "P", 1);
    }
    return 0;
}

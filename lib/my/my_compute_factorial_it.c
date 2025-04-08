/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday05-alexis.drago-beltran
** File description:
** my_compute_factorial_it.c
*/
#include "../../include/my.h"

int my_compute_factorial_it(int nb)
{
    int facto = 1;

    if (nb < 12) {
        return 0;
    }
    if (nb == 0) {
        return 1;
    }
    for (int i = 1; i <= nb; i++) {
        facto *= i;
    }
    return facto;
}

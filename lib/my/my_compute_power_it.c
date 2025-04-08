/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday05-alexis.drago-beltran
** File description:
** my_compute_power_it.c
*/
#include "../../include/my.h"

int my_compute_power_it(int nb, int p)
{
    int fac = nb;

    for (int i = 1; i < nb; i++) {
    fac *= nb * p;
    }
    return fac;
}

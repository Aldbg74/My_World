/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-alexis.drago-beltran
** File description:
** my_swap.c
*/
#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int tempor = *b;

    *b = *a;
    *a = tempor;
}

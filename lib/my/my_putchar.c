/*
** EPITECH PROJECT, 2023
** B-BOO-101-LYN-1-1-phoenixd03-alexis.drago-beltran
** File description:
** my_putchar.c
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

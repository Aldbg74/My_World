/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-alexis.drago-beltran
** File description:
** my_intlen.c
*/

#include "../../include/my.h"

int my_intlen(int value)
{
    int lenght = 0;
    long test_length = 1;

    if (value < 0) {
        value *= -1;
        lenght++;
    }
    while (test_length < value) {
        lenght++;
        test_length *= 10;
    }
    return lenght;
}

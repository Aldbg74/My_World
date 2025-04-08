/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-alexis.drago-beltran
** File description:
** my_str_isaplha.c
*/
#include "../../include/my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;
    char letter;

    for (i = 0; i != '\0'; i++) {
        if (letter >= 65 && letter <= 90)
            return 1;
        else
            return 0;
    }
    return 0;
}

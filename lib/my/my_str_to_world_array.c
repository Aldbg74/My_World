/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-alexis.drago-beltran
** File description:
** my_str_to_world_array.c
*/

#include "../../include/my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_alpha_num(char letter)
{
    if (letter >= '0' && letter <= '9' || letter >= 'a' && letter <= 'z'
        || letter >= 'A' && letter <= 'Z' || letter == '/' || letter == '-')
        return 1;
    else
        return 0;
}

int cont_the_world(char const *str)
{
    int n = 0;

    if (is_alpha_num(str[0]) == 1) {
        n++;
    }
    for (int k = 0; str[k] != '\0'; k++) {
        if (is_alpha_num(str[k]) == 0
            && is_alpha_num(str[k + 1]) == 1) {
            n++;
        }
    }
    return n;
}

void increm(int *ptrx, int *ptri)
{
    (*ptrx)++;
    (*ptri)++;
}

char **my_str_to_word_array(char const *str)
{
    int nb = cont_the_world(str);
    char **tab = malloc(sizeof(char *) * (nb + 1));
    int i = 0;
    int x = 0;
    int y = 0;

    while (str[i] != '\0') {
        tab[y] = malloc(sizeof(char) * (my_strlen(str) + 1));
        while (is_alpha_num(str[i]) == 0)
            i += 1;
        x = 0;
        while (str[i] != '\0' && is_alpha_num(str[i]) == 1) {
            tab[y][x] = str[i];
            increm(&x, &i);
        }
        tab[y][x] = '\0';
        increm(&y, &i);
    }
    tab[y] = 0;
    return (tab);
}

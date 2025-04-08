/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-alexis.drago-beltran
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

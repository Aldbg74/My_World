/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myprintf-alexis.drago-beltran
** File description:
** do_the_o.c
*/

#include "../../../../include/my.h"
#include "../../../../include/my_printf.h"
#include <stdlib.h>
#include <unistd.h>

int do_the_o(unsigned int nbr)
{
    char buffer[12];
    int i = 11;

    buffer[i] = '\0';
    i--;
    if (nbr == 0) {
        buffer[i] = '0';
        i--;
    } else {
        while (nbr > 0) {
            buffer[i] = (nbr % 8) + '0';
            nbr /= 8;
            i--;
        }
    }
    write(1, &buffer[i + 1], 11 - i);
    return 0;
}

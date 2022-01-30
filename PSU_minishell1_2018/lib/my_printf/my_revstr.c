/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** task03
*/

#include "../my/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int max = 0;
    char stock;

    while (str[i] != '\0')
        i++;
    max = i - 1;
    i = 0;
    while (i < max) {
        stock = str[i];
        str[i] = str[max];
        str[max] = stock;
        max--;
        i++;
    }
    return (str);
}
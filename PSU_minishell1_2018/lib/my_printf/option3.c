/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** option 3
*/

#include "my_printf.h"

int binary(char *str, va_list args, int i)
{
    int nb_char = 0;

    nb_char = decimal_binary(va_arg(args, unsigned int));
    return (nb_char);
}

int space(char *str, int i)
{
    while (str[i + 1] == ' ')
        i = i + 1;
    return (i);
}

int display_for_space(int nb_char, int i, int test)
{
    int za = 0;

    if (i != test) {
        za = 1;
        my_putchar(' ');
    }
    return (za);
}

int display_dieze(char *str, int nb_char, int i, int test)
{
    int a = 0;

    if (str[i] == '#' && str[i + 1] == 'o') {
        my_putchar('0');
        a = 1;
    }
    if (str[i] == '#' && str[i + 1] == 'x') {
        my_putstr("0x");
        a = 2;
    }
    if (str[i] == '#' && str[i + 1] == 'X') {
        my_putstr("0X");
        a = 2;
    }
    return (a);
}

int dieze(char *str, int nb_char, int i)
{
    while (str[i + 1] == '#')
        i = i + 1;
    return (i);
}
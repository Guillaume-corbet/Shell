/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** convert
*/

#include "my_printf.h"

int decimal_hexadecimal_upp(int nb)
{
    char *str;
    int tmp = 0;
    int i = 0;
    int zoulou = 0;

    str = malloc(sizeof(char) * (100));
    while (nb > 0) {
        tmp = nb % 16;
        nb = nb / 16;
        if (tmp < 10)
            str[i] = tmp + 48;
        else if (tmp > 9)
            str[i] = tmp + 55;
        i = i + 1;
    }
    str = my_revstr(str);
    my_putstr(str);
    zoulou = my_strlen(str);
    return (zoulou);
}

int decimal_hexadecimal_low(int nb)
{
    char *str;
    int tmp = 0;
    int i = 0;
    int zoulou = 0;

    str = malloc(sizeof(char) * (100));
    while (nb > 0) {
        tmp = nb % 16;
        nb = nb / 16;
        if (tmp < 10)
            str[i] = tmp + 48;
        else if (tmp > 9)
            str[i] = tmp + 87;
        i = i + 1;
    }
    str = my_revstr(str);
    my_putstr(str);
    zoulou = my_strlen(str);
    return (zoulou);
}

int decimal_octal(int nb)
{
    char *str;
    int tmp = 0;
    int i = 0;
    int zoulou = 0;

    str = malloc(sizeof(char) * 100);
    while (nb > 0) {
        tmp = nb % 8;
        nb = nb / 8;
        str[i] = tmp + 48;
        i = i + 1;
    }
    str = my_revstr(str);
    my_putstr(str);
    zoulou = my_strlen(str);
    return (zoulou);
}

int decimal_binary(unsigned int nb)
{
    char *str;
    int tmp = 0;
    int i = 0;
    int zoulou = 0;

    str = malloc(sizeof(char) * 100);
    while (nb > 0) {
        tmp = nb % 2;
        nb = nb / 2;
        str[i] = tmp + 48;
        i = i + 1;
    }
    str = my_revstr(str);
    my_putstr(str);
    zoulou = my_strlen(str);
    return (zoulou);
}

int int_to_str_print(int nb)
{
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * 11);
    while (nb > 0) {
        str[a] = (nb % 10) + 48;
        nb = nb / 10;
        a = a + 1;
    }
    str[a] = '\0';
    str = my_revstr(str);
    a = my_strlen(str);
    my_putstr(str);
    return (a);
}
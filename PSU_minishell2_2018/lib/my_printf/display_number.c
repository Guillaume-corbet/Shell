/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** display_number
*/

#include "my_printf.h"

int unsigned_to_str(unsigned int nb)
{
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * 11);
    while (nb > 0) {
        str[a] = (nb % 10) + 48;
        nb = nb / 10;
        a = a + 1;
    }
    str = my_revstr(str);
    a = my_strlen(str);
    my_putstr(str);
    return (a);
}

int my_put_adress(void *p)
{
    char const *base;
    int i = 8;
    int zoulou = 0;

    ADRESS;
    nb_yes = (unsigned long) p;
    base = "0123456789abcdef";
    while ((nb_yes / 16) > 0 || i >= 8) {
        res_yes[i] = base[(nb_yes % 16)];
        nb_yes = nb_yes / 16;
        i--;
        zoulou = zoulou + 1;
    }
    res_yes[i] = base[(nb_yes % 16)];
    zoulou = zoulou + 3;
    my_putstr("0x");
    while (i < 9) {
        my_putchar(res_yes[i]);
        i = i + 1;
    }
    return (zoulou);
}

int put_big_string(char *str)
{
    int number = 0;
    int counter = 0;
    char new_str[3];

    while (str[counter] != '\0') {
        if (str[counter] == 127) {
            my_putstr("\\177");
            number = number + 4;
        } else if (str[counter] < 32) {
            my_strcpy(new_str, other_octal(str[counter]));
            number = number + my_printf("%s", new_str);
        } else {
            my_putchar(str[counter]);
            number = number + 1;
        }
        counter = counter + 1;
    }
    return (number);
}

int number_str(char *str)
{
    int zoulou = 0;
    if (str == NULL) {
        my_putstr("(null)");
        zoulou = 6;
        return (zoulou);
    }
    zoulou = my_strlen(str);
    my_putstr(str);
    return (zoulou);
}

char *other_octal(int nb)
{
    char *str;
    int tmp = 0;
    int i = 0;
    int z = 2;
    int lenght = 0;

    str = malloc(sizeof(char) * 4);
    while (nb > 0) {
        tmp = nb % 8;
        nb = nb / 8;
        str[i] = tmp + 48;
        i = i + 1;
    }
    lenght = my_strlen(str);
    my_putchar('\\');
    while (z >= lenght) {
        my_putchar('0');
        z = z - 1;
    }
    str = my_revstr(str);
    return (str);
}
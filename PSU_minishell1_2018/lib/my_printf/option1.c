/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** option1
*/

#include "my_printf.h"

int string(char *str, va_list args, int i)
{
    int nb_str = 0;

    nb_str = number_str(va_arg(args, char *));
    return (nb_str);
}

int integer(char *str, va_list args, int i)
{
    int nb_str = 0;

    nb_str = int_to_str_print(va_arg(args, int));
    return (nb_str);
}

int modulo(char *str, va_list args, int i)
{
    int nb_str = 0;

    my_putchar('%');
    i = i + 1;
    nb_str = nb_str + 1;
    return (nb_str);
}

int character(char *str, va_list args, int i)
{
    int nb_str = 0;

    my_putchar((unsigned char)va_arg(args, int));
    nb_str = nb_str + 1;
    return (nb_str);
}

int big_string(char *str, va_list args, int i)
{
    int nb_str = 0;

    nb_str = put_big_string(va_arg(args, char *));
    return (nb_str);
}

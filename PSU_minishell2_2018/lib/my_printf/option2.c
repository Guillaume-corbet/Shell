/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** option2
*/

#include "my_printf.h"

int unsigned_integer(char *str, va_list args, int i)
{
    int nb_char = 0;

    nb_char = unsigned_to_str(va_arg(args, unsigned int));
    return (nb_char);
}

int hexadecimal_low(char *str, va_list args, int i)
{
    int nb_char = 0;

    nb_char = decimal_hexadecimal_low(va_arg(args, int));
    return (nb_char);
}

int hexadecimal_upp(char *str, va_list args, int i)
{
    int nb_char = 0;

    nb_char = decimal_hexadecimal_upp(va_arg(args, int));
    return (nb_char);
}

int pointer(char *str, va_list args, int i)
{
    int nb_char = 0;

    nb_char = my_put_adress(va_arg(args, void *));
    return (nb_char);
}

int octal(char *str, va_list args, int i)
{
    int nb_char = 0;

    nb_char = decimal_octal(va_arg(args, int));
    return (nb_char);
}

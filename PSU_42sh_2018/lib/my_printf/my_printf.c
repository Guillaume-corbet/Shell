/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** main
*/

#include "my_printf.h"

int inconnue(char *str, int z, int i)
{
    if (str[i + 1] == '\0') {
        return (0);
    }
    if (z > 11) {
        i = i + 1;
        my_putchar('%');
        my_putchar(str[i]);
        return (2);
    } else
        return (0);
}

int my_printf3(char *str, va_list args, int i, int nb_char)
{
    int (*fp[12])(char *, va_list, int);
    char *op = "sdi%cuxXpoSb";
    int z = -1;

    fp[0] = &string;
    fp[1] = &integer;
    fp[2] = &integer;
    fp[3] = &modulo;
    fp[4] = &character;
    fp[5] = &unsigned_integer;
    fp[6] = &hexadecimal_low;
    fp[7] = &hexadecimal_upp;
    fp[8] = &pointer;
    fp[9] = &octal;
    fp[10] = &big_string;
    fp[11] = &binary;
    while (op[++z] != str[i + 1]) {
        if (z > 10)
            return (inconnue(str, z, i));
    }
    return (fp[z](str, args, i));
}

int my_printf2(char *str, va_list args, ...)
{
    int i = 0;
    int nb_char = 0;
    int test = 0;

    while (str[i] != '\0') {
        if (str[i] != '%') {
            my_putchar(str[i]);
            i = i + 1;
            nb_char = nb_char + 1;
        } else if (str[i] == '%') {
            test = space(str, i);
            nb_char = nb_char + display_for_space(nb_char, i, test);
            i = test;
            test = dieze(str, nb_char, i);
            i = test;
            nb_char = nb_char + display_dieze(str, nb_char, i, test);
            nb_char = nb_char + my_printf3(str, args, i, nb_char);
            i = i + 2;
        }
    }
    return (nb_char);
}

int my_printf(char *str, ...)
{
    int result = 0;
    va_list(ap);

    va_start(ap, str);
    result = my_printf2(str, ap);
    va_end(ap);
    return (result);
}

/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** search_char
*/

#include "../minishell.h"

int search_char(char *str, char c)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == c)
            return (TRUE);
        i += 1;
    }
    return (FALSE);
}
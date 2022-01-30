/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** var2
*/

#include "../minishell.h"

int count_dollar(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '$')
            count = count + 1;
        i = i + 1;
    }
    return (i);
}

char *search_var(char *var, char *str, int i)
{
    int a = 0;

    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t') {
        var[a] = str[i];
        a = a + 1;
        i = i + 1;
    }
    var[a] = '\0';
    return (var);
}
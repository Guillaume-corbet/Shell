/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change_or
*/

#include "../minishell.h"

char *change_or(char *str)
{
    int i = 0;

    while (str[i + 1] != '\0') {
        if (str[i] == '|' && str[i + 1] == '|') {
            str[i] = '~';
            str[i + 1] = '~';
        }
        i = i + 1;
    }
    return (str);
}

char *change_all(char *str, minishell_t *mini)
{
    if (mini->first != NULL)
        str = change_str_to_alias(str, mini);
    str = change_var(str, mini);
    str = change_or(str);
    return (str);
}
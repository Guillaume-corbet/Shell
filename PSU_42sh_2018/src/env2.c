/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** env2
*/

#include "../minishell.h"

int my_strcmp_env(char *str, char *compare)
{
    int i = 0;

    while (str[i] != '=' && compare[i] != '=') {
        if (str[i] != compare[i])
            return (1);
        i = i + 1;
    }
    return (0);
}
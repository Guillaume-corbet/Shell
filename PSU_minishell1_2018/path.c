/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** path
*/

#include "minishell.h"

char *stock_path(char **envp)
{
    int i = 0;
    char *str;

    while (envp[i] != NULL) {
        if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T'
        && envp[i][3] == 'H' && envp[i][4] == '=') {
            if ((str = malloc(sizeof(char) * my_strlen(envp[i]) + 1)) == NULL)
                return (NULL);
            str = fill_str(str, my_strlen(envp[i]));
            my_strcpy(str, envp[i]);
        }
        i = i + 1;
    }
    return (str);
}

char **str_tab_path(char *str)
{
    char **tab;
    int i = 5;
    int x = 0;
    int y = 0;

    if ((tab = malloc(sizeof(char *) * 100)) == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if ((tab[x] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
            return (NULL);
        tab[x] = fill_str(tab[x], my_strlen(str) + 1);
        while (str[i] != ':' && str[i] != '\0') {
            tab[x][y] = str[i];
            i = i + 1;
            y = y + 1;
        }
        if (str[i] != '\0')
            i = i + 1;
        y = 0;
        x = x + 1;
    }
    tab[x] = NULL;
    return (tab);
}
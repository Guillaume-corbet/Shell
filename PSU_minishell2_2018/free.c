/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** free
*/

#include "minishell.h"

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i = i + 1;
    }
    free(tab);
}

void free_all(char *str, char **tab, char **tab_path)
{
    free_tab(tab);
    free_tab(tab_path);
    free(str);
}
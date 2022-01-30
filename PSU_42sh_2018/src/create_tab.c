/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** create_tab
*/

#include "../minishell.h"

char **create_tab(char **tab)
{
    static int i = 0;
    int x = 0;
    char **new_tab;

    if ((new_tab = malloc(sizeof(char *) * length_tab(tab + 1))) == NULL)
        return (NULL);
    if (my_strcmp(tab[i], ";") == 0)
        i = i + 1;
    while (my_strcmp(tab[i], ";") != 0 && tab[i] != NULL) {
        new_tab[x] = my_strcpy(new_tab[x], tab[i]);
        x = x + 1;
        i = i + 1;
    }
    i = i + 1;
    return (new_tab);
}
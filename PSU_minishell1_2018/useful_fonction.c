/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** useful_fonction
*/

#include "minishell.h"

char **list_to_tab(rlist *p_list)
{
    char **tab;
    int i = 0;
    int x = 0;

    if ((tab = malloc(sizeof(char *) * p_list->length + 1)) == NULL)
        return (NULL);
    while (p_list->length != 0) {
        if ((tab[x] = malloc(sizeof(char) * 1000)) == NULL)
            return (NULL);
        my_strcpy(tab[x], p_list->p_head->str);
        dlist_remove(p_list, 1);
        x = x + 1;
    }
    return (tab);
}

void tab_to_list(char **tab, rlist *p_list)
{
    int x = 0;

    while (tab[x] != NULL) {
        dlist_append(p_list, tab[x]);
        free(tab[x]);
        x = x + 1;
    }
    free(tab);
}
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** unalias
*/

#include "../minishell.h"

int findalias(char *alias, alias_t *first)
{
    alias_t *tmp = first;

    while (tmp) {
        if (my_strcmp(tmp->name, alias) == 0)
            return (TRUE);
        else
            tmp = tmp->next;
    }
    return (FALSE);
}

void remove_alias(alias_t *toremove, minishell_t *shell)
{
    if (toremove != shell->first && toremove != shell->last) {
        toremove->prev->next = toremove->next;
        toremove->next->prev = toremove->prev;
    }
    if (toremove == shell->first && toremove->next) {
        toremove->next->prev = NULL;
        shell->first = toremove->next;
    }
    if (toremove == shell->last && toremove->prev) {
        toremove->prev->next = NULL;
        shell->last = toremove->prev;
    }
    if (toremove == shell->last && toremove == shell->first) {
        shell->first = NULL;
        shell->last = NULL;
    }
    free(toremove);
}

void loopunalias(char *alias, minishell_t *shell)
{
    alias_t *tmp = shell->first;

    while (tmp) {
        if (my_strcmp(tmp->name, alias) == 0) {
            remove_alias(tmp, shell);
            return;
        }
        else
            tmp = tmp->next;
    }
}

void function_unalias(char **tab, minishell_t *shell)
{
    alias_t *tmp = shell->first;

    if (!tab[1]) {
        my_printf("unalias: Too few arguments\n");
        return;
    }
    if (my_strcmp(tab[1], "*") == 0) {
        while (tmp) {
            remove_alias(tmp, shell);
            tmp = shell->first;
        }
    }
    for (int i = 1; tab[i]; i++) {
        loopunalias(tab[i], shell);
    }
}
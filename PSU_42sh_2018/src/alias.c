/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** alias
*/

#include "../minishell.h"

alias_t *create_first(void)
{
    alias_t *new = malloc(sizeof(alias_t));

    new->name = NULL;
    new->next = NULL;
    new->prev = NULL;
    new->instru = NULL;
    return (new);
}

alias_t *addalias(alias_t *previous)
{
    alias_t *new = malloc(sizeof(alias_t));

    new->name = NULL;
    new->next = NULL;
    new->prev = previous;
    new->instru = NULL;
    previous->next = new;
    return (new);
}

void print_alias(alias_t *first)
{
    alias_t *tmp = first;

    while (tmp) {
        if (search_char(tmp->instru, ' ') == TRUE)
            my_printf("%s\t(%s)\n", tmp->name, tmp->instru);
        else
            my_printf("%s\t%s\n", tmp->name, tmp->instru);
        tmp = tmp->next;
    }
}

char *get_instruction(char **tab)
{
    char *instruction = NULL;
    int i = 2;

    for (i = 2; tab[i + 1]; i++) {
        if (instruction == NULL)
            instruction = strdup(tab[i]);
        else
            instruction = m_strcat(instruction, tab[i]);
        instruction = m_strcat(instruction, " ");
    }
    if (instruction == NULL)
        instruction = strdup(tab[i]);
    else
        instruction = m_strcat(instruction, tab[i]);
    return (instruction);
}

void function_alias(char **tab, minishell_t *shell)
{
    if (!tab[1] && shell->first) {
        print_alias(shell->first);
    } else if (tab[1] && tab[2] && findalias(tab[1], shell->first) == FALSE) {
        if (!shell->first) {
            shell->first = create_first();
            shell->first->name = malloc(sizeof(char) * (strlen(tab[1]) + 1));
            shell->first->name = my_strcpy(shell->first->name, tab[1]);
            shell->first->instru = get_instruction(tab);
            shell->last = shell->first;
        } else {
            shell->last = addalias(shell->last);
            shell->last->name = malloc(sizeof(char) * (my_strlen(tab[1]) + 1));
            shell->last->name = my_strcpy(shell->last->name, tab[1]);
            shell->last->instru = get_instruction(tab);
        }
    }
    return;
}
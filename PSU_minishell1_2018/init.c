/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** init
*/

#include "minishell.h"

minishell_t *init(char **envp)
{
    minishell_t *mi;

    if ((mi = malloc(sizeof(minishell_t))) == NULL)
        exit(84);
    mi->bufs = 100;
    mi->charac = 0;
    mi->status = 0;
    mi->length_old = 0;
    if ((mi->str = malloc(sizeof(char) * 100)) == NULL)
        exit(84);
    mi->str = fill_str(mi->str, 100);
    if ((mi->str_path = stock_path(envp)) == NULL)
        exit(84);
    if ((mi->tab_path = str_tab_path(mi->str_path)) == NULL)
        exit(84);
    return (mi);
}

void init_tab(minishell_t *mi)
{
    display_prompt();
    if ((mi->charac = getline(&mi->str, &mi->bufs, stdin)) == -1)
        exit(84);
    if ((mi->tab = str_to_word_array(mi->str)) == NULL)
        exit(84);
}
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** creat_tab
*/

#include "../minishell.h"

char ***creat_tab(char **new_tab, char **tab_path, char **envp)
{
    char ***all_tab = malloc(sizeof(char *) * 4);
    all_tab[0] = new_tab;
    all_tab[1] = tab_path;
    all_tab[2] = envp;
    all_tab[3] = 0;
    return (all_tab);
}
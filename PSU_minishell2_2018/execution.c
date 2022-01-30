/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** execution
*/

#include "minishell.h"

void function_execution(char **tab, char **tab_pat, char **envp)
{
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * 1000);
    str = my_strcpy(str, tab_pat[a]);
    str = my_strcat(str, "/");
    str = my_strcat(str, tab[0]);
    while (execve(str, tab, envp) == -1) {
        a = a + 1;
        if (tab_pat[a] == NULL && (tab_pat) && execve(tab[0], tab, envp) == -1)
            verif_func(tab, str);
        str = my_strcpy(str, tab_pat[a]);
        str = my_strcat(str, "/");
        str = my_strcat(str, tab[0]);
    }
}
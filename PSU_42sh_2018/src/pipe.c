/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** pipe
*/

#include "../minishell.h"

char **init_pipe(char *str)
{
    char **tab;

    tab = str_to_word_array_sec(str, '|');
    if (verif_redirect_pipe(tab) == 84) {
        my_putstr("Ambiguous output redirect.\n");
        return (NULL);
    }
    return (tab);
}

void verif_cd_pipe(char **tab, int *i, minishell_t *mini)
{
    char **new_tab;

    new_tab = str_to_word_array(tab[*i]);
    take_normal(tab[(*i) + 1], mini, i);
    if (my_strcmp(new_tab[0], "cd") == 0)
        function_cd_pipe(mini, new_tab);
    chdir(search_path(mini->p_list, "PWD"));
}

void pid_zero_pipe(char **path, minishell_t *mini, char **envp, char **tab)
{
    if (function_add(tab, envp, mini, 1) == 0)
        exe_min_4(path, envp, tab, mini);
    else
        exit(0);
}

int verif_last_pipe(char *str)
{
    int i = my_strlen(str);

    if (str[i - 2] == '|')
        return (84);
    return (0);
}

int search_pipes(char *str)
{
    int i = 0;

    while (str[i + 1] != '\0') {
        if (str[i] == '|' && str[i + 1] != '|' && str[i + 1] != '\0') {
            return (1);
        }
        i = i + 1;
    }
    return (0);
}
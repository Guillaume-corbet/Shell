/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** minishell
*/

#include "minishell.h"

int minishell_3(minishell_t *mini, char **envp, char *str)
{
    char **new_tab;
    int result_fonc_add = 0;
    char **tab_path;

    tab_path = search_tab_path(mini->p_list);
    if ((new_tab = str_to_word_array(str)) == NULL)
        return (84);
    result_fonc_add = function_add(new_tab, envp, mini);
    if (result_fonc_add == 0) {
        if (tab_path != NULL && tab_path[0] != NULL)
            fonction_fork(new_tab, tab_path, envp);
        else
            fonction_fork(new_tab, mini->tab_path, envp);
    } else if (result_fonc_add == 84)
        return (84);
    free_tab(new_tab);
    return (0);
}

int minishell_4(minishell_t *mini, char **envp, char *str)
{
    char **tab;
    int i = 0;
    int status = 0;
    char **new_tab;
    char **tab_path;

    tab = str_to_word_array_sec(str, '|');
    while (tab[i] != NULL) {
        tab_path = search_tab_path(mini->p_list);
        pipe(mini->redir->pipe_fd);
        PID_MINI = fork();
        if (mini->redir->pid == 0) {
            new_tab = init_pid_zero(tab, i, mini);
            exe_min_4(tab_path, mini->tab_path, envp, new_tab);
        } else {
            init_pid_not_zero(tab[i + 1], status, mini);
        }
        take_normal(tab[i + 1], mini);
        i = i + 1;
    }
}

int search_pipes(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '|')
            return (1);
        i = i + 1;
    }
    return (0);
}

int minishell(minishell_t *mini, char **envp)
{
    char **tab;
    int i = 0;

    if ((tab = init_command()) == NULL)
        return (84);
    while (tab[i] != NULL) {
        if (search_pipes(tab[i]) == 1) {
            minishell_4(mini, envp, tab[i]);
        } else if (minishell_3(mini, envp, tab[i]) == 84)
            return (84);
        i = i + 1;
    }
    return (0);
}
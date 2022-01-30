/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** minishell2
*/

#include "minishell.h"

void take_normal(char *str, minishell_t *mini)
{
    if (str == NULL) {
        dup2(mini->redir->stdin, 0);
        dup2(mini->redir->stdout, 1);
    }
}

void exe_min_4(char **tab_path, char **tab_pat, char **envp, char **tab)
{
    if (tab_path != NULL && tab_path[0] != NULL)
        function_execution(tab, tab_path, envp);
    else
        function_execution(tab, tab_pat, envp);
}

char **init_pid_zero(char **tab, int i, minishell_t *mini)
{
    char **new_tab;

    new_tab = str_to_word_array(tab[i]);
    close(mini->redir->pipe_fd[0]);
    if (tab[i + 1] != NULL)
        dup2(mini->redir->pipe_fd[1], 1);
    return (new_tab);
}

void init_pid_not_zero(char *str, int status, minishell_t *mini)
{
    if (str == NULL) {
        while ((PID_MINI == waitpid(PID_MINI, &status, WNOHANG)) == 0);
        verif_status(status);
    }
    close(mini->redir->pipe_fd[1]);
    dup2(mini->redir->pipe_fd[0], 0);
}
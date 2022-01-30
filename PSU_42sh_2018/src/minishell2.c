/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** minishell2
*/

#include "../minishell.h"

void take_normal(char *str, minishell_t *mini, int *i)
{
    if (str == NULL) {
        dup2(mini->redir->stdin, 0);
        dup2(mini->redir->stdout, 1);
    }
    (*i) = (*i) + 1;
}

void exe_min_4(char **tab_path, char **envp, char **tab, minishell_t *mini)
{
    if (tab_path != NULL && tab_path[0] != NULL)
        function_execution(creat_tab(tab, tab_path, envp), 0, mini);
    else
        function_execution(creat_tab(tab, mini->tab_path, envp), 0, mini);
}

char **init_pid_zero(char **tab, int i, minishell_t *mini)
{
    char **new_tab;

    new_tab = str_to_word_array(tab[i]);
    if (mini->redir->fd != 0 && mini->redir->fd != -1)
        close(mini->redir->fd);
    if (i == 0 || tab[i + 1] == NULL) {
        if (search_redirection(mini, new_tab, 1) == 84)
            return (NULL);
    }
    close(mini->redir->pipe_fd[0]);
    if (tab[i + 1] != NULL)
        dup2(mini->redir->pipe_fd[1], 1);
    return (new_tab);
}

void init_pid_not_zero(char *str, minishell_t *mini)
{
    int status = 0;

    if (str == NULL) {
        while ((PID_MINI == waitpid(PID_MINI, &status, WNOHANG)) == 0);
        verif_status(status);
    }
    close(mini->redir->pipe_fd[1]);
    dup2(mini->redir->pipe_fd[0], 0);
}

int minishell_4(minishell_t *mini, char **envp, char *str)
{
    char **tab = init_pipe(str);
    int i = 0;
    char **new_tab;
    char **tab_path;

    if (tab == NULL || verif_last_pipe(str) == 84)
        return (ERROR);
    while (tab[i] != NULL) {
        tab_path = search_tab_path(mini->p_list);
        pipe(mini->redir->pipe_fd);
        PID_MINI = fork();
        if (mini->redir->pid == 0) {
            if ((new_tab = init_pid_zero(tab, i, mini)) == NULL)
                return (84);
            pid_zero_pipe(tab_path, mini, envp, new_tab);
        } else {
            init_pid_not_zero(tab[i + 1], mini);
        }
        verif_cd_pipe(tab, &i, mini);
    }
    return (0);
}
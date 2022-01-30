/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** redirect_out
*/

#include "../minishell.h"

int redirect_simple_out(minishell_t *mini, char ***tab, int i)
{
    if ((*tab)[i + 1] == NULL) {
        my_putstr("Missing name for redirect.\n");
        return (ERROR);
    } else if (i == 0) {
        my_putstr("Invalid null command.\n");
        return (ERROR);
    }
    mini->redir->fd = open((*tab)[i + 1], O_WRONLY | O_TRUNC);
    if (mini->redir->fd == -1) {
        mini->redir->fd = open((*tab)[i + 1], O_CREAT | O_WRONLY, 0666);
        if (mini->redir->fd == -1)
            return (ERROR);
    }
    dup2(mini->redir->fd, 1);
    (*tab)[i] = NULL;
    return (0);
}

int redirect_double_out(minishell_t *mini, char ***tab, int i)
{
    if ((*tab)[i + 1] == NULL) {
        my_putstr("Missing name for redirect.\n");
        return (ERROR);
    } else if (i == 0) {
        my_putstr("Invalid null command.\n");
        return (ERROR);
    }
    mini->redir->fd = open((*tab)[i + 1], O_WRONLY | O_APPEND);
    if (mini->redir->fd == -1) {
        mini->redir->fd = open((*tab)[i + 1], O_CREAT | O_WRONLY, 0666);
        if (mini->redir->fd == -1)
            return (ERROR);
    }
    dup2(mini->redir->fd, 1);
    (*tab)[i] = NULL;
    return (0);
}

int search_redirection_out(minishell_t *mini, char ***tab, int i)
{
    if (my_strcmp((*tab)[i], ">") == 0) {
        if (redirect_simple_out(mini, (tab), i) == ERROR)
            return (ERROR);
    } else if (my_strcmp((*tab)[i], ">>") == 0) {
        if (redirect_double_out(mini, (tab), i) == ERROR)
            return (ERROR);
    } else {
        return (42);
    }
    return (0);
}
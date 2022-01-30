/*
** EPITECH PROJECT, 2019
** *
** File description:
** pipe
*/

#include "minishell.h"

int search_pipe(redi_t *redir)
{
    if (redir->pipe >= 2) {
        if (dup2(redir->fd, 1) == -1)
            return (84);
        if (dup2(redir->fd, 0) == -1)
            return (84);
    } else if (redir->pipe == 1) {
        if (dup2(redir->fd, 0) == -1)
            return (84);
    }
    return (0);
}

int verif_redirection(redi_t *redir)
{
    if (redir->pipe >= 2) {
        if (dup2(redir->stdout, 1) == -1)
            return (84);
        if (dup2(redir->stdin, 0) == -1)
            return (84);
        redir->pipe = redir->pipe - 1;
    } else if (redir->pipe == 1) {
        if (dup2(redir->stdin, 0) == -1)
            return (84);
        redir->pipe = redir->pipe - 1;
    }
    return (0);
}
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** redirect
*/

#include "../minishell.h"

void come_back_redirection(minishell_t *mini)
{
    if (mini->redir->fd != 0 && mini->redir->fd != -1) {
        dup2(mini->redir->stdin, 0);
        dup2(mini->redir->stdout, 1);
        close(mini->redir->fd);
    }
}

int verif_redirect(char **tab)
{
    int count = 0;
    int other = 0;
    int i = 0;

    while (tab[i] != NULL) {
        if (tab[i][0] == '>')
            count = count + 1;
        else if (tab[i][0] == '<')
            other = other + 1;
        i = i + 1;
    }
    if (count > 1 || other > 1) {
        my_putstr("Ambiguous output redirect.\n");
        return (ERROR);
    }
    return (0);
}

int search_redirection(minishell_t *mini, char **tab, int pipe)
{
    int i = 0;
    int result = 0;

    if (pipe == 0) {
        if (verif_redirect(tab) == 84)
            return (ERROR);
    }
    while (tab[i] != NULL) {
        result = search_redirection_out(mini, &tab, i);
        if (result == ERROR)
            return (ERROR);
        else if (result == 42)
            result = search_redirection_in(mini, &tab, i);
        result = result;
        if (result == ERROR)
            return (ERROR);
        i = i + 1;
    }
    return (0);
}

int verif_redirect_pipe_sec(char **tab)
{
    int i = 1;
    int x = 0;

    while (tab[i + 1] != NULL) {
        while (tab[i][x] != '\0') {
            if (tab[i][x] == '>' || tab[i][x] == '<')
                return (84);
            x = x + 1;
        }
        x = 0;
        i = i + 1;
    }
    return (0);
}

int verif_redirect_pipe(char **tab)
{
    int i = 0;
    int x = length_tab(tab) - 1;

    while (tab[0][i] != '\0') {
        if (tab[0][i] == '>')
            return (ERROR);
        i = i + 1;
    }
    i = 0;
    while (tab[x][i] != '\0') {
        if (tab[x][i] == '<')
            return (ERROR);
        i = i + 1;
    }
    if (verif_redirect_pipe_sec(tab) == 84)
        return (ERROR);
    return (0);
}
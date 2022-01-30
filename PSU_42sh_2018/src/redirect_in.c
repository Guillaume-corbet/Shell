/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** redirect_in
*/

#include "../minishell.h"

int redirect_simple_in(minishell_t *mini, char ***tab, int i)
{
    if ((*tab)[i + 1] == NULL) {
        my_putstr("Missing name for redirect.\n");
        return (ERROR);
    } else if (i == 0) {
        my_putstr("Invalid null command.\n");
        return (ERROR);
    }
    mini->redir->fd = open((*tab)[i + 1], O_RDONLY);
    if (mini->redir->fd == -1)
        return (ERROR);
    dup2(mini->redir->fd, 0);
    (*tab)[i] = NULL;
    return (0);
}

int redirection_double_in_sec(minishell_t *mini, char ***tab, int i, char *s)
{
    mini->redir->fd = open(".poubelle", O_WRONLY | O_TRUNC);
    if (mini->redir->fd == -1) {
        mini->redir->fd = open(".poubelle", O_CREAT | O_WRONLY, 0666);
        if (mini->redir->fd == -1)
            return (ERROR);
    }
    write(mini->redir->fd, s, my_strlen(s));
    close(mini->redir->fd);
    (*tab)[i] = my_strcpy((*tab)[i], "<");
    (*tab)[i + 1] = my_strcpy((*tab)[i + 1], ".poubelle");
    redirect_simple_in(mini, tab, i);
}

int redirect_double_in(minishell_t *mini, char ***tab, int i)
{
    size_t bufs = 1000;
    char *str = malloc(sizeof(char) * bufs + 1);
    char *new_str = malloc(sizeof(char) * (10 * bufs));

    if ((*tab)[i + 1] == NULL || str == NULL || new_str == NULL) {
        my_putstr("Missing name for redirect.\n");
        return (ERROR);
    } else if (i == 0) {
        my_putstr("Invalid null command.\n");
        return (ERROR);
    }
    (*tab)[i + 1] = my_strcat((*tab)[i + 1], "\n");
    my_putstr("? ");
    while (getline(&str, &bufs, stdin) != -1
    && my_strcmp(str, (*tab)[i + 1]) != 0) {
        new_str = my_strcat(new_str, str);
        my_putstr("? ");
    }
    if (redirection_double_in_sec(mini, tab, i, new_str) == ERROR)
        return (ERROR);
    return (0);
}

int search_redirection_in(minishell_t *mini, char ***tab, int i)
{
    if (my_strcmp((*tab)[i], "<") == 0) {
        if (redirect_simple_in(mini, (tab), i) == ERROR)
            return (ERROR);
    } else if (my_strcmp((*tab)[i], "<<") == 0) {
        if (redirect_double_in(mini, (tab), i) == ERROR)
            return (ERROR);
    }
    return (0);
}
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** built_in
*/

#include "../minishell.h"

int add_fct_fourth(char **tab, char **envp, minishell_t *mini, int pipe)
{
    if (my_strcmp(tab[0], "alias") == 0) {
        function_alias(tab, mini);
        return (42);
    } else if (my_strcmp(tab[0], "unalias") == 0) {
        function_unalias(tab, mini);
        return (42);
    } else
        return (0);
}

int add_fct_third(char **tab, char **envp, minishell_t *mini, int pipe)
{
    if (my_strcmp(tab[0], "unsetenv") == 0) {
        function_unsetenv(mini, tab);
        return (42);
    } else if (my_strcmp(tab[0], "echo") == 0) {
        function_echo(tab);
        return (42);
    } else
        return (add_fct_fourth(tab, envp, mini, pipe));
}

int add_fct_sec(char **tab, char **envp, minishell_t *mini, int pipe)
{
    if (my_strcmp(tab[0], "cd") == 0 && tab[1] != NULL) {
        if (pipe == 0) {
            if (function_cd(mini->sto_cd, tab) == 84)
                return (84);
        } else
            function_cd_pipe(mini, tab);
        return (42);
    } else if (my_strcmp(tab[0], "setenv") == 0) {
        if (tab[1] == NULL)
            display_env(mini->p_list);
        else
            mini->p_list = function_setenv(mini->p_list, tab);
        return (42);
    } else
        return (add_fct_third(tab, envp, mini, pipe));
}

int function_add(char **tab, char **envp, minishell_t *mini, int pipe)
{
    if (my_strcmp(tab[0], "exit") == 0) {
        if (isatty(0))
            my_putstr("exit\n");
        exit(0);
    } else if (my_strcmp(tab[0], "env") == 0)
        display_env(mini->p_list);
    else
        return (add_fct_sec(tab, envp, mini, pipe));
}
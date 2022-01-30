/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** main2
*/

#include "minishell.h"

int function_add(char **tab, char **envp, minishell_t *mini)
{
    if (my_strcmp(tab[0], "exit") == 0)
        exit(0);
    else if (my_strcmp(tab[0], "env") == 0)
        display_env(mini->p_list);
    else if (my_strcmp(tab[0], "cd") == 0 && tab[1] != NULL) {
        if (function_cd(mini->sto_cd, tab) == 84)
            return (84);
    } else if (my_strcmp(tab[0], "setenv") == 0) {
        if (tab[1] == NULL)
            display_env(mini->p_list);
        else
            function_setenv(mini->p_list, tab);
    } else if (my_strcmp(tab[0], "unsetenv") == 0) {
        function_unsetenv(mini->p_list, tab);
    } else {
        return (0);
    }
    return (42);
}

int fonction_fork(char **new_tab, char **tab_path, char **envp)
{
    pid_t pid = 0;
    int status = 0;

    if ((pid = fork()) == -1)
        return (84);
    if (pid == 0)
        function_execution(new_tab, tab_path, envp);
    else {
        while ((pid == waitpid(pid, &status, WNOHANG)) == 0);
        verif_status(status);
    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    minishell_t *mini;

    if ((mini = init_struct_minishell(envp)) == NULL)
        return (84);
    while (1) {
        if (minishell(mini, envp) == 84)
            return (84);
    }
    return (0);
}

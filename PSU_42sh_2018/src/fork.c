/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** fork
*/

#include "../minishell.h"

int exist_func_depth(char *tmp_two, char *tmp_one, char **new)
{
    int k = -1;

    while (new[++k]) {
        tmp_two = m_strcat(tmp_one, new[k]);
        if (access(tmp_two, X_OK) == 0 || access(new[k], X_OK) == 0)
            return (1);
    }
    k = -1;
    return (0);
}

int exist_func(char **new, char **tab_path, int error)
{
    char *tmp_one = NULL;
    char *tmp_two = NULL;
    int i = -1;

    if (error != 0)
        return (error);
    while (tab_path[++i]) {
        tmp_one = m_strcat(tab_path[i], "/");
        if (exist_func_depth(tmp_two, tmp_one, new))
            return (0);
    }
    return (1);
}

int fonction_fork(char **new, char **tab_path, char **envp, minishell_t *mini)
{
    char **new_tab_tmp = new;
    int comp = 0;
    int comp2 = 0;
    int error = 0;
    int exec_return = 0;

    if (error_and(new, 0, 0))
        return (84);
    op_logique(&new, &new_tab_tmp, &comp);
    while (1) {
        exec_return = exec_fork(&error, comp2,
        creat_tab(new, tab_path, envp), mini);
        if (exec_return)
            return (exec_return - 1);
        error = exist_func(new, tab_path, error);
        new = set_value_in_fonction(&comp2, &comp, new_tab_tmp);
        op_logique(&new, &new_tab_tmp, &comp);
        if (comp == 0 && comp2 == 0)
            return (0);
    }
}

int exec_fork(int *error, int comp2, char ***all_tab, minishell_t *mini)
{
    pid_t pid = 0;
    int status = 0;
    
    if (*error && comp2 == 2 || !*error && comp2 == 1 ||
    comp2 != 1 && comp2 != 2) {
        if ((pid = fork()) == -1)
            return (85);
        if (pid == 0)
            function_execution(all_tab, error, mini);
        else {
            while ((pid == waitpid(pid, &status, WNOHANG)) == 0);
            verif_status(status);
        }
    } else if (comp2 == 2)
        return (1);
    *error = status;
    return (0);
}
/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** minishell
*/

#include "../minishell.h"

int minishell_3(minishell_t *mini, char **envp, char *str)
{
    char **new_tab;
    int result_fonc_add = 0;
    char **tab_path = search_tab_path(mini->p_list);

    if ((new_tab = str_to_word_array(str)) == NULL)
        return (84);
    if (tab_path != NULL && my_strcmp(tab_path[0], "/") == 0) {
        my_printf("%s: Command not found.\n", new_tab[0]);
        return (0);
    } if (search_redirection(mini, new_tab, 0) == 84)
        return (42);
    result_fonc_add = function_add(new_tab, envp, mini, 0);
    if (result_fonc_add == 0) {
        if (tab_path != NULL && tab_path[0] != NULL)
            fonction_fork(new_tab, tab_path, envp, mini);
        else
            fonction_fork(new_tab, mini->tab_path, envp, mini);
    } else if (result_fonc_add == 84)
        return (84);
    come_back_redirection(mini);
    return (0);
}

int minishell(minishell_t *mini, char **envp)
{
    char **tab;
    int i = 0;
    int result = 0;

    if ((tab = init_command(mini)) == NULL)
        return (84);
    while (tab[i] != NULL) {
        if (search_pipes(tab[i]) == 1) {
            if (minishell_4(mini, envp, tab[i]) == 84) {
                return (0);
            }
        } else if ((result = minishell_3(mini, envp, tab[i])) != 0)
            return (result);
        i = i + 1;
    }
    return (0);
}
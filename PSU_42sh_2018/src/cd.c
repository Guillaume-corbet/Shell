/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** cd.c
*/

#include "../minishell.h"

int function_cd(stock_cd_t *sto_cd, char **tab)
{
    size_t bufs = 1000;

    if (getcwd(sto_cd->new_pwd, bufs) == NULL)
        return (84);
    if (my_strcmp(tab[1], "-") == 0) {
        if (chdir(sto_cd->old_pwd) == -1)
            my_printf("%s: Not a directory.\n", sto_cd->old_pwd);
        else
            sto_cd->old_pwd = my_strcpy(sto_cd->old_pwd, sto_cd->new_pwd);
    } else if (chdir(tab[1]) == -1)
        my_printf("%s: Not a directory.\n", tab[1]);
    else
        sto_cd->old_pwd = my_strcpy(sto_cd->old_pwd, sto_cd->new_pwd);
    return (0);
}

void function_cd_pipe(minishell_t *mini, char **tab)
{
    char *str = malloc(sizeof(char) * 1000);
    char **tabs;
    size_t bufs = 1000;

    tabs = malloc(sizeof(char *) * 4);
    tabs[0] = malloc(sizeof(char) * 10);
    tabs[1] = malloc(sizeof(char) * 1000);
    tabs[2] = malloc(sizeof(char) * 1000);
    tabs[3] = NULL;
    chdir(tab[1]);
    getcwd(str, bufs);
    tabs[0] = my_strcpy(tabs[0], "setenv");
    tabs[1] = my_strcpy(tabs[1], "PWD");
    tabs[2] = my_strcpy(tabs[2], str);
    mini->p_list = function_setenv(mini->p_list, tabs);
    free_tab(tabs);
}
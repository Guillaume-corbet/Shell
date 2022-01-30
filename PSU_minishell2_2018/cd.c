/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** cd.c
*/

#include "minishell.h"

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

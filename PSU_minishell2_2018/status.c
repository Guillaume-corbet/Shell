/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** status
*/

#include "minishell.h"

void verif_status(int status)
{
    if (WIFSIGNALED(status) == 1 && WTERMSIG(status) != 8)
        my_putstr("Segmentation fault\n");
    else if (WIFSIGNALED(status) == 1 && WTERMSIG(status) == 8)
        my_putstr("Floating exception\n");
}

void verif_func(char **tab, char *str)
{
    if (errno == ENOEXEC) {
        my_printf("%s: ", tab[0]);
        my_printf(ARCHI);
    } else if (errno == EACCES)
        my_printf("%s: Permission denied.\n", tab[0]);
    else
        my_printf("%s: Command not found.\n", tab[0]);
    free(str);
    free_tab(tab);
    exit(0);
}
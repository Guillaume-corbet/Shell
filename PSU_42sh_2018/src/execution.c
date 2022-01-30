/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** execution
*/

#include "../minishell.h"

void function_execution(char ***tab, int *error, minishell_t *mini)
{
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * 1000);
    str = my_strcpy(str, tab[1][a]);
    str = my_strcat(str, "/");
    str = my_strcat(str, tab[0][0]);
    while (execve(str, tab[0], tab[2]) == -1) {
        a = a + 1;
        if (tab[1][a] == NULL && (tab[1]) &&
            execve(tab[0][0], tab[0], tab[2]) == -1 && error)
            *error = 1;
        if (tab[1][a] == NULL && (tab[1]) &&
        execve(tab[0][0], tab[0], tab[2]) == -1) {
            verif_func(tab[0], str, mini);
        }
        str = my_strcpy(str, tab[1][a]);
        str = my_strcat(str, "/");
        str = my_strcat(str, tab[0][0]);
    }
}
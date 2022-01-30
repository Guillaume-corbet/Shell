/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** echo
*/

#include "../minishell.h"

void display_tab_echo(char **tab)
{
    int i = 0;

    if (my_strcmp(tab[1], "-n") == 0) {
        i = 2;
        my_putstr(tab[i]);
        i = i + 1;
        while (tab[i] != NULL) {
            my_putchar(' ');
            my_putstr(tab[i]);
            i = i + 1;
        }
    } else {
        i = 1;
        my_putstr(tab[i]);
        i = i + 1;
        while (tab[i] != NULL) {
            my_putchar(' ');
            my_putstr(tab[i]);
            i = i + 1;
        }
    }
}

int function_echo(char **tab)
{
    if (tab[1] == NULL)
        my_putchar('\n');
    else if (tab[2] == NULL) {
        if (my_strcmp(tab[1], "-n") != 0) {
            my_putstr(tab[1]);
            my_putchar('\n');
        } else {
            return (0);
        }
    } else {
        if (my_strcmp(tab[1], "-n") == 0) {
            display_tab_echo(tab);
        } else {
            display_tab_echo(tab);
            my_putchar('\n');
        }
    }
    return (0);
}
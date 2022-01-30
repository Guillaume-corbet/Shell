/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** env
*/

#include "minishell.h"

int fonc_setenv_arg_3(char *new_env, int length_old, char **tab, rlist *p_list)
{
    new_env = new_env + length_old;
    new_env = my_strcat(new_env, tab[1]);
    new_env = my_strcat(new_env, "=");
    new_env = my_strcat(new_env, tab[2]);
    length_old = my_strlen(new_env);
    dlist_append(p_list, new_env);
    return (length_old);
}

int fonc_setenv(char **tab, int nbr_tab, int length_old, rlist *p_list)
{
    char *new_env;

    if ((new_env = malloc(sizeof(char) * 100)) == NULL)
        return (-84);
    my_putchar('A');
    if (nbr_tab > 1 && tab[1][0] < 65 || (tab[1][0] > 90 && tab[1][0] < 97) ||
    tab[1][0] > 122) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return (length_old);
    }
    my_putchar('B');
    if (nbr_tab == 3) {
        length_old = fonc_setenv_arg_3(new_env, length_old, tab, p_list);
    } else if (nbr_tab == 2) {
        new_env = new_env + length_old;
        new_env = my_strcat(new_env, tab[1]);
        new_env = my_strcat(new_env, "=");
        length_old = my_strlen(new_env);
        dlist_append(p_list, new_env);
    }
    return (length_old);
}

void fonc_env(rlist *p_list, char **tab)
{
    int a = 0;
    rlist *tmp = p_list;

    while (a < p_list->length) {
        my_putstr(tmp->p_head->str);
        my_putchar('\n');
        tmp->p_head = tmp->p_head->p_next;
        a = a + 1;
    }
    if (my_strcmp(tab[0], "setenv") == 1) {
        exit(0);
    }
}

void fonc_unsetenv(minishell_t *mi, rlist *p_list)
{
    int a = 0;

    mi->tab[1] = my_strcat(mi->tab[1], "=");
    while (a < p_list->length) {
        if (my_strncmp(mi->tab[1], p_list->p_head->str,
        my_strlen(mi->tab[1])) == 0) {
            dlist_remove(p_list, 1);
            a = a - 1;
        } else {
            dlist_append(p_list, p_list->p_head->str);
            dlist_remove(p_list, 1);
        }
        a = a + 1;
    }
}
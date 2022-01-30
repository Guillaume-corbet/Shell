/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** env
*/

#include "../minishell.h"

void display_env(rlist *p_list)
{
    struct node *tmp = p_list->p_head;

    while (tmp != NULL) {
        my_putstr(tmp->str);
        my_putchar('\n');
        tmp = tmp->p_next;
    }
}

char *set_char_setenv(char **tab)
{
    char *str;

    if ((str = malloc(sizeof(char) * 1000)) == NULL)
        return (NULL);
    str = my_strcpy(str, tab[1]);
    str = my_strcat(str, "=");
    if (tab[2] != NULL)
        str = my_strcat(str, tab[2]);
    return (str);
}

int verif_letter(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 122) {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return (84);
        } else if (str[i] > 57 && str[i] < 65) {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return (84);
        } else if (str[i] > 90 && str[i] < 97) {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return (84);
        }
        i = i + 1;
    }
    return (0);
}

rlist *function_setenv(rlist *p_list, char **tab)
{
    int i = 0;
    struct node *tmp = p_list->p_head;
    struct node *nd = malloc(sizeof(struct node));
    char *str;

    if (verif_letter(tab[1]) == 84)
        return (NULL);
    str = malloc(sizeof(char) * 1000);
    while (i < p_list->length) {
        if (my_strcmp_env(tab[1], tmp->str) == 0) {
            str = set_char_setenv(tab);
            tmp->str = my_strcpy(tmp->str, str);
            return (p_list);
        }
        tmp = tmp->p_next;
        i = i + 1;
    }
    str = set_char_setenv(tab);
    nd = add_node_end(str, p_list->p_tail);
    add_element(nd, p_list);
    return (p_list);
}

void function_unsetenv(minishell_t *mini, char **tab)
{
    struct node *tmp = mini->p_list->p_head;
    int i = 0;

    while (tmp->p_next != NULL) {
        if (my_strcmp_env(tab[1], tmp->str) == 0)
            remove_element(mini->p_list, i);
        i = i + 1;
        tmp = tmp->p_next;
    }
}
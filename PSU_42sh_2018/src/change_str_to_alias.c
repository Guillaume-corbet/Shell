/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change_str_to_alias
*/

#include "../minishell.h"

int search_str(char *str, char *alias)
{
    int i = 0;
    int a = 0;
    int y = 0;

    while (str[i] != '\0') {
        a = i;
        while (str[a] != '\0' && alias[y] != '\0' && str[a] == alias[y]) {
            a = a + 1;
            y = y + 1;
        }
        if (alias[y] == '\0')
            return (i);
        y = 0;
        i = i + 1;
    }
    return (-84);
}

char *realloc_str_alias(char *str, alias_t *t, int place)
{
    int i = 0;
    int a = 0;
    int lenght = my_strlen(str) - my_strlen(t->name) + my_strlen(t->instru);
    char *new_str = malloc(sizeof(char) * lenght + 1);

    while (i < place) {
        new_str[i] = str[i];
        i = i + 1;
    }
    a = i;
    new_str[i] = '\0';
    new_str = my_strcat(new_str, t->instru);
    i = i + my_strlen(t->instru);
    a = a + my_strlen(t->name);
    while (str[a] != '\0') {
        new_str[i] = str[a];
        a = a + 1;
        i = i + 1;
    }
    new_str[i] = '\0';
    return (new_str);
}

char *change_str_to_alias(char *str, minishell_t *mini)
{
    int i = -84;
    int change = 1;
    alias_t *tmp = mini->first;
    alias_t *tmp2 = mini->first;

    while (1) {
        i = search_str(str, tmp->name);
        if (i != -84) {
            str = realloc_str_alias(str, tmp, i);
            change = 1;
        }
        tmp = tmp->next;
        if (tmp == NULL && change == 0)
            break;
        if (tmp == NULL) {
            change = 0;
            tmp = tmp2;
        }
    }
    return (str);
}
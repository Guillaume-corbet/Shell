/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** path
*/

#include "minishell.h"

char *search_path(rlist *p_list)
{
    struct node *tmp = p_list->p_head;
    char *str;

    while (tmp != NULL) {
        if (my_strcmp_env(tmp->str, "PATH") == 0) {
            str = malloc(sizeof(char) * my_strlen(tmp->str) + 1);
            str = my_strcpy(str, tmp->str);
            return (str);
        }
        tmp = tmp->p_next;
    }
    return (NULL);
}

char **search_tab_path(rlist *p_list)
{
    char **tab_path;
    char *str;
    int i = 5;
    int a = 0;

    if ((str = malloc(sizeof(char) * 1000)) == NULL)
        return (NULL);
    if ((str = search_path(p_list)) == NULL)
        return (NULL);
    while (str[i] != '\0') {
        str[a] = str[i];
        a = a + 1;
        i = i + 1;
    }
    str[a] = '\0';
    if ((tab_path = str_to_word_array_sec(str, ':')) == NULL)
        return (NULL);
    return (tab_path);
}
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** var
*/

#include "../minishell.h"

char *realloc_str_var(char *str, char *change, char *var, int place)
{
    int i = 0;
    int a = 0;
    int lenght = my_strlen(str) - my_strlen(var) - 1 + my_strlen(change);
    char *new_str = malloc(sizeof(char) * lenght + 1);

    while (i < place) {
        new_str[i] = str[i];
        i = i + 1;
    }
    a = i;
    new_str[i] = '\0';
    new_str = my_strcat(new_str, change);
    i = i + my_strlen(change);
    a = a + my_strlen(var) + 1;
    while (str[a] != '\0') {
        new_str[i] = str[a];
        a = a + 1;
        i = i + 1;
    }
    new_str[i] = '\0';
    return (new_str);
}

void change_var_sec(char *str, int *i, int *times)
{
    while (str[(*i)] != '$' && str[(*i)] != '\0')
        (*i) = (*i) + 1;
    if (str[*i] == '$' && (str[*i] == ' ' ||
    str[*i] == '\t' || str[*i] == '\n')) {
        (i) = (i) + 1;
        (*times) = (*times) - 1;
    }
}

char *change_var_third(char *str, char **change, char *var, int i)
{
    if ((*change) != NULL) {
        while ((*change)[0] != '=') {
            (*change) = (*change) + 1;
        }
        (*change) = (*change) + 1;
        str = realloc_str_var(str, (*change), var, i);
    }
    return (str);
}

char *change_var(char *str, minishell_t *mini)
{
    int times = count_dollar(str);
    int i = 0;
    char *var = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *change;

    if (str[my_strlen(str) - 1] == '$')
        times = times - 1;
    while (times > 0 && str[i] != '\0') {
        change_var_sec(str, &i, &times);
        if (str[i] == '$') {
            var = search_var(var, str, i + 1);
            i = i + 1;
            times = times - 1;
            change = search_path(mini->p_list, var);
            str = change_var_third(str, &change, var, i - 1);
            free(var);
            var = malloc(sizeof(char) * (my_strlen(str) + 1));
        }
    }
    return (str);
}
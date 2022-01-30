/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** str_to_word_array
*/

#include "minishell.h"

int supress_space(char *str, int i)
{
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' && str[i] != '\0')
        i = i + 1;
    return (i);
}

int count_words(char *str)
{
    int number = 0;
    int i = 0;
    int y = 0;

    i = supress_space(str, i);
    while (str[i] != '\0') {
        y = i;
        i = supress_space(str, i);
        if (i != y)
            number = number + 1;
        if (str[i] != '\0')
            i = i + 1;
    }
    number = number + 2;
    return (number);
}

char **str_to_word_array(char *str)
{
    char **tab;
    int i = 0;
    int x = 0;
    int y = 0;

    if ((tab = malloc(sizeof(char *) * count_words(str))) == NULL)
        return (NULL);
    i = supress_space(str, i);
    while (STR) {
        if ((tab[x] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
            return (NULL);
        tab[x] = fill_str(tab[x], my_strlen(str) + 1);
        while (STR && str[i] != '\n' && str[i] != ' ' && str[i] != '\t') {
            tab[x][y] = str[i];
            i = i + 1;
            y = y + 1;
        }
        i = supress_space(str, i);
        y = 0;
        x = x + 1;
    }
    tab[x] = NULL;
    return (tab);
}
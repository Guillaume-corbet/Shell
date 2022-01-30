/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** fill
*/

char *fill_str(char *str, int x)
{
    int i = 0;

    while (i < x) {
        str[i] = '\0';
        i = i + 1;
    }
    return (str);
}
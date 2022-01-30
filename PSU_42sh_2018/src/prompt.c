/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** prompt
*/

#include "../minishell.h"

int display_prompt(void)
{
    char *cwd;
    size_t bufs = 1000;

    if ((cwd = malloc(sizeof(char) * 1000)) == NULL)
        return (84);
    my_putchar('[');
    if (getcwd(cwd, bufs) == NULL)
        return (84);
    my_putstr(cwd);
    my_putchar(']');
    my_putstr("$ ");
    free(cwd);
    return (0);
}
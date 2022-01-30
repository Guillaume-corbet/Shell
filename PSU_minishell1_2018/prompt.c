/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** prompt
*/

#include "minishell.h"

void display_prompt(void)
{
    char *cwd;
    size_t bufs = 100;

    if ((cwd = malloc(sizeof(char) * 100)) == NULL)
        exit(84);
    my_putchar('[');
    if (getcwd(cwd, bufs) == NULL)
        exit(84);
    my_putstr(cwd);
    my_putchar(']');
    my_putstr("$ ");
    free(cwd);
}
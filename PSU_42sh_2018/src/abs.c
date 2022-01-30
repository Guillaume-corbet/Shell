/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** abs
*/

#include "../minishell.h"

int abs_val(int nbr)
{
    int neg = -1;

    if (nbr < 0)
        return (nbr * neg);
    else
        return (nbr);
}
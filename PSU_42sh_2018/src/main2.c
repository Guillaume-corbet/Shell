/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** main2
*/

#include "../minishell.h"

void op_logique(char ***new_tab, char ***new_tab_tmp, int *comp)
{
    for (int i = 0; (*new_tab)[i] && *comp == 0; i++) {
        if (!my_strcmp((*new_tab)[i], "&&")) {
            *comp = 1;
            *new_tab_tmp += i + 1;
            (*new_tab)[i] = 0;
        } else if (!my_strcmp((*new_tab)[i], "~~")) {
            *comp = 2;
            *new_tab_tmp += i + 1;
            (*new_tab)[i] = 0;
        }
    }
}

int error_and(char **new, int separ2, int separ)
{
    if (!my_strcmp(new[0], "~~") || !my_strcmp(new[0], "&&")) {
        write(2, "Invalid null command.\n", 22);
        return (84);
    }
    for (int i = 0; new[i]; i++) {
        separ = 0;
        if (!my_strcmp(new[i], "~~") || !my_strcmp(new[i], "&&"))
            separ = 1;
        if (separ == 1 && separ2 == 1) {
            write(2, "Invalid null command.\n", 22);
            return (84);
        }
        separ2 = separ;
    }
    if (separ == 1) {
        write(2, "Invalid null command.\n", 22);
        return (84);
    }
    return (0);
}

char **set_value_in_fonction(int *comp2, int *comp, char **new_tab_tmp)
{
    *comp2 = *comp;
    *comp = 0;
    return (new_tab_tmp);
}

int main(int argc, char **argv, char **envp)
{
    minishell_t *mini;

    if ((mini = init_struct_minishell(envp)) == NULL)
        return (84);
    while (1) {
        if (minishell(mini, envp) == 84)
            return (84);
    }
    return (0);
}

/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** init
*/

#include "minishell.h"

minishell_t *init_struct_minishell(char **envp)
{
    minishell_t *mini;

    if ((mini = malloc(sizeof(minishell_t))) == NULL)
        return (NULL);
    if ((mini->redir = init_struct_redirection()) == NULL)
        return (NULL);
    if ((mini->sto_cd = init_struct_cd()) == NULL)
        return (NULL);
    if ((mini->p_list = init_env(mini->p_list, envp)) == NULL)
        return (NULL);
    if ((mini->tab_path = str_to_word_array_sec(SECU_PATH, ':')) == NULL)
        return (NULL);
    return (mini);
}

stock_cd_t *init_struct_cd(void)
{
    stock_cd_t *sto_cd;

    if ((sto_cd = malloc(sizeof(stock_cd_t))) == NULL)
        return (NULL);
    else if ((sto_cd->old_pwd = malloc(sizeof(char) * 1000)) == NULL)
        return (NULL);
    else if ((sto_cd->new_pwd = malloc(sizeof(char) * 1000)) == NULL)
        return (NULL);
    return (sto_cd);
}

redi_t *init_struct_redirection(void)
{
    redi_t *redir;

    if ((redir = malloc(sizeof(redi_t))) == NULL)
        exit(84);
    if ((redir->pipe_fd = malloc(sizeof(int) * 3)) == NULL)
        exit(84);
    redir->pid = 0;
    redir->stdin = dup(0);
    redir->stdout = dup(1);
    return (redir);
}

char **init_command(void)
{
    size_t bufs = 1000;
    char **tab;
    int charac = 1;
    char *str;

    if ((str = malloc(sizeof(char) * 1000)) == NULL)
        return (NULL);
    while (charac == 1) {
        if (display_prompt() == 84)
            return (NULL);
        if ((charac = getline(&str, &bufs, stdin)) == -1)
            exit(0);
        if (str[0] == '|') {
            my_putstr("Invalid null command.\n");
            charac = 1;
        }
    }
    if ((tab = str_to_word_array_sec(str, ';')) == NULL)
        return (NULL);
    free(str);
    return (tab);
}

rlist *init_env(rlist *p_list, char **envp)
{
    struct node *nd;
    int i = 0;

    if (envp[i] == NULL)
        return (NULL);
    nd = init_node(envp[i]);
    p_list = dlist_new(nd);
    add_element(nd, p_list);
    i = i + 1;
    while (envp[i] != NULL) {
        nd = add_node_end(envp[i], p_list->p_tail);
        add_element(nd, p_list);
        i = i + 1;
    }
    return (p_list);
}

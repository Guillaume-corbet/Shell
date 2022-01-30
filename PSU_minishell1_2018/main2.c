/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** main2
*/

#include "minishell.h"

int length_tab(char **tab)
{
    int x = 0;

    while (tab[x] != NULL) {
        x = x + 1;
    }
    return (x);
}

stock_cd_t *init_struct_cd(void)
{
    stock_cd_t *sto_cd;

    if ((sto_cd = malloc(sizeof(stock_cd_t))) == NULL)
        exit(84);
    else if ((sto_cd->old_pwd = malloc(sizeof(char) * 1000)) == NULL)
        exit(84);
    else if ((sto_cd->new_pwd = malloc(sizeof(char) * 1000)) == NULL)
        exit(84);
    return (sto_cd);
}

void fonction_execution(char *str, char **tab, char **tab_path, char **envp)
{
    int a = 0;
    
    str = my_strcpy(str, tab_path[a]);
    str = my_strcat(str, "/");
    str = my_strcat(str, tab[0]);
    while (execve(str, tab, envp) == -1) {
        a = a + 1;
        if (a == length_tab(tab_path) && execve(tab[0], tab, envp) == -1) {
            my_printf("%s: Command not found.\n", tab[0]);
            free_tab(tab);
            exit(0);
        }
        str = my_strcpy(str, tab_path[a]);
        str = my_strcat(str, "/");
        str = my_strcat(str, tab[0]);
    }
}

void verif_status(int status)
{
    if (status == 139 || status == 11)
        write(1, "Segmentation fault\n", 20);
    if (status == 136 || status == 6)
        write(1, "Floating exception\n", 20);
}

void fonction_cd(stock_cd_t *sto_cd, char **tab)
{
    size_t bufs = 1000;

    if (getcwd(sto_cd->new_pwd, bufs) == NULL)
        exit(84);
    if (my_strcmp(tab[1], "-") == 0) {
        if (chdir(sto_cd->old_pwd) == -1)
            my_printf("%s: Not a directory.\n");
        else
            sto_cd->old_pwd = my_strcpy(sto_cd->old_pwd, sto_cd->new_pwd);
    } else if (chdir(tab[1]) == -1)
        my_printf("%s: Not a directory.\n", tab[1]);
    else
        sto_cd->old_pwd = my_strcpy(sto_cd->old_pwd, sto_cd->new_pwd);
}

void display_env(char **envp)
{
    int i = 0;

    while (envp[i] != NULL) {
        my_putstr(envp[i]);
        my_putchar('\n');
        i = i + 1;
    }
}

int main(int argc, char **argv, char **envp)
{
    pid_t pid = 0;
    size_t bufs = 1000;
    int status = 0;
    int charac = 1;
    char *str;
    char **tab;
    char **tab_path;
    stock_cd_t *sto_cd;
    
    if ((sto_cd = init_struct_cd()) == NULL)
        exit(84);
    if ((str = malloc(sizeof(char) * 1000)) == NULL)
        exit(84);
    tab_path = str_tab_path(stock_path(envp));
    while (1) {
        charac = 1;
        while (charac == 1) {
            display_prompt();
            if ((charac = getline(&str, &bufs, stdin)) == -1)
                exit(0);
        }
        tab = str_to_word_array(str);
        if (my_strcmp(str, "exit\n") == 0) {
            exit(0);
        } else if (my_strcmp(str, "env\n") == 0)
            display_env(envp);
        else if (my_strcmp(tab[0], "cd") == 0 && tab[1] != NULL)
            fonction_cd(sto_cd, tab);
        else {
            if ((pid = fork()) == -1) {
                free_all(str, tab, tab_path);
                exit(84);
            }
            if (pid == 0)
                fonction_execution(str, tab, tab_path, envp);
            while ((pid == waitpid(pid, &status, WNOHANG)) == 0);
            verif_status(status);
        }
    }
    return (0);
}
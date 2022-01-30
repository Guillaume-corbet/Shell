/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "lib/my/my.h"
#include "lib/my_printf/my_printf.h"
#include "errno.h"

#define PID_MINI mini->redir->pid
#define STR (str[i] != '\0')
#define FLAG_OPEN O_CREAT, O_RDWR, S_IRUSR, S_IWUSR, S_IRGRP, S_IROTH
#define ARCHI "Exec format error. Wrong Architecture.\n"
#define SECU_PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

struct node
{
    char *str;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
}rlist;

typedef struct stock_cd
{
    char *new_pwd;
    char *old_pwd;
}stock_cd_t;

typedef struct redi
{
    int *pipe_fd;
    int pid;
    int stdin;
    int stdout;
}redi_t;

typedef struct t_minishell
{
    redi_t *redir;
    stock_cd_t *sto_cd;
    rlist *p_list;
    char **tab_path;
}minishell_t;

rlist *dlist_new(struct node *new);
struct node *init_node(char *str);
struct node *add_node_end(char *str, struct node *old);
void add_element(struct node *new, rlist *p_list);
rlist *remove_element(rlist *p_list, int position);

int length_tab(char **tab);
void display_tab(char **tab);

int supress_space(char *str, int i);
int count_words(char *str);
void intern_while_one(int *i, int *y, int *x, int a);
char **str_to_word_array(char *str);
char **str_to_word_array_sec(char *str, char c);

int display_prompt(void);

void function_execution(char **tab, char **tab_path, char **envp);

char *fill_str(char *str, int i);

void free_tab(char **tab);
void free_all(char *str, char **tab, char **tab_path);

int function_cd(stock_cd_t *sto_cd, char **tab);

void verif_status(int status);
void verif_func(char **tab, char *str);

void display_env(rlist *p_list);
char *set_char_setenv(char **tab);
rlist *function_setenv(rlist *p_list, char **tab);
rlist *function_unsetenv(rlist *p_list, char **tab);

minishell_t *init_struct_minishell(char **envp);
stock_cd_t *init_struct_cd(void);
redi_t *init_struct_redirection(void);
char **init_command(void);
rlist *init_env(rlist *p_list, char **envp);

char **take_command(char **tab, int *i);
int function_add(char **tab, char **envp, minishell_t *mini);
int fonction_fork(char **new_tab, char **tab_path, char **envp);
int my_strcmp_env(char *str, char *compare);

int minishell(minishell_t *mini, char **envp);
int minishell3(minishell_t *mini, char **envp, char *str);
int minishell4(minishell_t *mini, char **envp, char *str);
int search_pipes(char *str);

int search_pipe(redi_t *redir);
int verif_redirection(redi_t *redir);

char *search_path(rlist *p_list);
char **search_tab_path(rlist *p_list);

void take_normal(char *str, minishell_t *mini);
void exe_min_4(char **tab_path, char **tab_pat, char **enpv, char **tab);
char **init_pid_zero(char **tab, int i, minishell_t *mini);
void init_pid_not_zero(char *str, int status, minishell_t *mini);

#endif /* !MINISHELL_H_ */

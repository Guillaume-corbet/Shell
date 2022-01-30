/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** header for 42sh
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

#define TRUE 0
#define FALSE 1
#define ERROR 84
#define PROBLEM 1
#define SUCCESS 0

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
    int fd;
    int stdin;
    int stdout;
}redi_t;

typedef struct alias
{
    char *name;
    char *instru;
    struct alias *prev;
    struct alias *next;
}alias_t;

typedef struct t_minishell
{
    redi_t *redir;
    stock_cd_t *sto_cd;
    struct alias *first;
    struct alias *last;
    rlist *p_list;
    char **tab_path;
    char *hist_path;
}minishell_t;

#ifndef INC_
#define INC_

/* redirect_in.c */

int redirect_simple_in(minishell_t *mini, char ***tab, int i);
int redirection_double_in_sec(minishell_t *mini, char ***tab, int i, char *s);
int redirect_double_in(minishell_t *mini, char ***tab, int i);
int search_redirection_in(minishell_t *mini, char ***tab, int i);

/* free.c */

void free_tab(char **tab);
void free_all(char *str, char **tab, char **tab_path);

/* redirect_out.c */

int redirect_simple_out(minishell_t *mini, char ***tab, int i);
int redirect_double_out(minishell_t *mini, char ***tab, int i);
int search_redirection_out(minishell_t *mini, char ***tab, int i);

/* status.c */

void verif_status(int status);
void verif_func(char **tab, char *str, minishell_t *mini);

/* abs.c */

int abs_val(int nbr);

/* add_to_list.c */

rlist *dlist_new(struct node *new);
struct node *init_node(char *str);
struct node *add_node_end(char *str, struct node *old);
void add_element(struct node *new, rlist *p_list);
rlist *remove_element(rlist *p_list, int position);

/* env2.c */

int my_strcmp_env(char *str, char *compare);

/* minishell.c */

int minishell_3(minishell_t *mini, char **envp, char *str);
int minishell(minishell_t *mini, char **envp);

/* search_char.c */

int search_char(char *str, char c);

/* create_tab.c */

char **create_tab(char **tab);

/* fill_str.c */

char *fill_str(char *str, int x);

/* minishell2.c */

void take_normal(char *str, minishell_t *mini, int *i);
void exe_min_4(char **tab_path, char **envp, char **tab, minishell_t *mini);
char **init_pid_zero(char **tab, int i, minishell_t *mini);
void init_pid_not_zero(char *str, minishell_t *mini);
int minishell_4(minishell_t *mini, char **envp, char *str);

/* var.c */

char *realloc_str_var(char *str, char *change, char *var, int place);
void change_var_sec(char*str, int *i, int *times);
char *change_var_third(char *str, char **change, char *var, int i);

/* change_str_to_alias.c */

int search_str(char *str, char *alias);
char *realloc_str_alias(char *str, alias_t *t, int place);
char *change_str_to_alias(char *str, minishell_t *mini);

/* var2.c */

int count_dollar(char *str);
char *search_var(char *var, char *str, int i);

/* built_in.c */

int add_fct_fourth(char **tab, char **envp, minishell_t *mini, int pipe);
int add_fct_third(char **tab, char **envp, minishell_t *mini, int pipe);
int add_fct_sec(char **tab, char **envp, minishell_t *mini, int pipe);
int function_add(char **tab, char **envp, minishell_t *mini, int pipe);

/* creat_tab.c */

char ***creat_tab(char **new_tab, char **tab_path, char **envp);

/* unalias.c */

int findalias(char *alias, alias_t *first);
void remove_alias(alias_t *toremove, minishell_t *shell);
void loopunalias(char *alias, minishell_t *shell);
void function_unalias(char **tab, minishell_t *shell);

/* prompt.c */

int display_prompt(void);

/* env.c */

void display_env(rlist *p_list);
char *set_char_setenv(char **tab);
int verif_letter(char *str);
rlist *function_setenv(rlist *p_list, char **tab);
void function_unsetenv(minishell_t *mini, char **tab);

/* help_tab.c */

void display_tab(char **tab);
int length_tab(char **tab);

/* alias.c */

alias_t *create_first(void);
alias_t *addalias(alias_t *previous);
void print_alias(alias_t *first);
char *get_instruction(char **tab);
void function_alias(char **tab, minishell_t *shell);

/* change_or.c */

char *change_or(char *str);
char *change_all(char *str, minishell_t *mini);

/* path.c */

char *search_path(rlist *p_list, char *new_str);
char **search_tab_path(rlist *p_list);

/* cd.c */

int function_cd(stock_cd_t *sto_cd, char **tab);
void function_cd_pipe(minishell_t *mini, char **tab);

/* init.c */

minishell_t *init_struct_minishell(char **envp);
stock_cd_t *init_struct_cd(void);
redi_t *init_struct_redirection(void);
char **init_command(minishell_t *mini);
rlist *init_env(rlist *p_list, char **envp);

/* str_to_word_array.c */

int supress_space(char *str, int i);
int count_words(char *str);
void intern_while_one(int *i, int *y, int *x, int a);
char **str_to_word_array(char *str);
char **str_to_word_array_sec(char *str, char c);

/* execution.c */

void function_execution(char ***tab, int *error, minishell_t *mini);

/* redirect.c */

void come_back_redirection(minishell_t *mini);
int verif_redirect(char **tab);
int search_redirection(minishell_t *mini, char **tab, int pipe);
int verif_redirect_pipe_sec(char **tab);
int verif_redirect_pipe(char **tab);

/* fork.c */

int fonction_fork(char **new, char **tab_path, char **envp, minishell_t *mini);
int exec_fork(int *error, int comp2, char ***all_tab, minishell_t *mini);

/* m_strcat.c */

void mem_set(void *buf, int c, size_t len);
char *m_strcat(char *fus, char *ion);

/* main2.c */

void op_logique(char ***new_tab, char ***new_tab_tmp, int *comp);
int error_and(char **new, int separ2, int separ);
char **set_value_in_fonction(int *comp2, int *comp, char **new_tab_tmp);
int main(int argc, char **argv, char **envp);

/* echo.c */

void display_tab_echo(char **tab);
int function_echo(char **tab);

/* pipe.c */

char **init_pipe(char *str);
void verif_cd_pipe(char **tab, int *i, minishell_t *mini);
void pid_zero_pipe(char **path, minishell_t *mini, char **envp, char **tab);
int verif_last_pipe(char *str);
int search_pipes(char *str);

char *change_var(char *str, minishell_t *mini);

#endif /* !INC_ */
#endif /* !MINISHELL_H_ */
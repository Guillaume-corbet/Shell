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

#define STR (str[i] != '\0')

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

rlist *dlist_new(void);
void dlist_remove_second(rlist *p_list, struct node *p_new, int position);
void dlist_remove_third(rlist *p_list, struct node *p_new, int position, int i);
void dlist_remove(rlist *p_list, int position);

void dlist_append_second(rlist *p_list, struct node *p_new);
int dlist_append(rlist *p_list, char *str);
void dlist_prepend_second(rlist *p_list, struct node *p_new);
int dlist_prepend(rlist *p_list, char *str);

char *stock_path(char **envp);
char **str_tab_path(char *str);

char **str_to_word_array(char *str);
char **list_to_tab(rlist *p_list);
void tab_to_list(char **tab, rlist *p_list);
int length_tab(char **tab);

void display_prompt(void);

void fonc_execution_second(char **envp, char **tab, int nbr_path, int a);
void fonc_execution(rlist *p_list, char **tab, char **tab_path, int nbr_path);

char *fill_str(char *str, int i);

void free_tab(char **tab);
void free_all(char *str, char **tab, char **tab_path);

#endif /* !MINISHELL_H_ */

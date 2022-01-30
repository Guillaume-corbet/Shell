/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** add_to_list
*/

#include "minishell.h"

void dlist_append_second(rlist *p_list, struct node *p_new)
{
    if (p_list->p_tail == NULL) {
        p_new->p_prev = NULL;
        p_list->p_head = p_new;
        p_list->p_tail = p_new;
    } else {
        p_list->p_tail->p_next = p_new;
        p_new->p_prev = p_list->p_tail;
        p_list->p_tail = p_new;
    }
    p_list->length = p_list->length + 1;
}

int dlist_append(rlist *p_list, char *str)
{
    if (p_list != NULL) {
        struct node *p_new;
        if ((p_new = malloc(sizeof(*p_new))) == NULL)
            return (84);
        if (p_new != NULL) {
            p_new->str = my_strcpy(p_new->str, str);
            p_new->p_next = NULL;
            dlist_append_second(p_list, p_new);
        }
    }
}

void dlist_prepend_second(rlist *p_list, struct node *p_new)
{
    if (p_list->p_tail == NULL) {
        p_new->p_next = NULL;
        p_list->p_head = p_new;
        p_list->p_tail = p_new;
    } else {
        p_list->p_head->p_prev = p_new;
        p_new->p_next = p_list->p_head;
        p_list->p_head = p_new;
    }
    p_list->length = p_list->length + 1;
}

int dlist_prepend(rlist *p_list, char *str)
{
    if (p_list != NULL) {
        struct node *p_new;
        if ((p_new = malloc(sizeof(*p_new))) == NULL)
            return (84);
        if (p_new != NULL) {
            p_new->str = my_strcpy(p_new->str, str);
            p_new->p_prev = NULL;
            dlist_prepend_second(p_list, p_new);
        }
    }
    return (0);
}
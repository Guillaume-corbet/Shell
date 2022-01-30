/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** strcat with malloc
*/

#include "../minishell.h"

void mem_set(void *buf, int c, size_t len)
{
    size_t i = 0;
    char *ptr = (char *)buf;

    while (i < len) {
        ptr[i] = c;
        i += 1;
    }
}

char *m_strcat(char *fus, char *ion)
{
    char *fusion = NULL;
    int len = my_strlen(fus) + my_strlen(ion) + 2;
    int k = 0;

    if ((fusion = malloc(sizeof(char *) * len)) == NULL)
        return (NULL);
    mem_set(fusion, '\0', len);
    for (int i = 0; fus[i] != '\0'; i++) {
        fusion[k] = fus[i];
        k++;
    }
    for (int i = 0; ion[i] != '\0'; i++) {
        fusion[k] = ion[i];
        k++;
    }
    return (fusion);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:26:35 by marvin            #+#    #+#             */
/*   Updated: 2023/04/03 19:26:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int ft_strlen (char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_free_stash(char **stash)
{
    if (stash && *stash)
    {
        free(*stash);
        *stash = NULL;
    }
    return (NULL);
}


char    *ft_strjoin_gnl(char *stash, char *buffer)
{
    size_t    i;
    size_t    j;
    size_t    size;
    char    *final;

    size = ft_strlen(stash) + ft_strlen(buffer);
    if (!size)
        return (ft_free_stash(&stash));
    final = malloc(sizeof(char) * (size + 1));
    if (!final)
        return (ft_free_stash(&stash));
    i = 0;
    j = 0;
    if (stash)
    {
        while (stash[i] && j < size)
            final[j++] = stash[i++];
    }
    i = 0;
    while (buffer[i] && j < size)
        final[j++] = buffer[i++];
    final[j] = '\0';
    free(stash);
    return (final);
}

int    ft_newline(char *stach) // Look for a /n in the line in parameter
{
    size_t i;

    i = 0;
    if (stach)
        while(stach[i])
            {
                if (stach[i] == '\n')
                    return (1);
                    i++;
            }
    return (0);
}
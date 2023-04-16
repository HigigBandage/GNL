/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:29:55 by marvin            #+#    #+#             */
/*   Updated: 2023/04/16 19:29:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *read_and_stach(int fd, char *stash) /* User read to add to the stach */
{    
    char *buff;
    ssize_t readed;

    buff = malloc(sizeof(char) * (BUFFER_SIZE +1));
    if (buff == NULL)
        return (0);
    while (!found_newline(*stash) && readed != 0)
    {    
        readed = read(fd, buff, BUFFER_SIZE);
        if (stash == NULL && readed != 0 || readed == -1)
            {
                free(buff);
                return;
            }
        buff[readed] = '/0';
    }
    stash = ft_strjoin_gnl(stash, buff);
    return (stash);    
}

char *extract_line(char * stash) /* Extract all the charachter from our stach and store them in out ine (stop at first \n) */
{
    int i;
    int j;
    char *line;

    if (stash == NULL)
        return (NULL);
    i = 0;
    while (stash[i] && stash != '\n')
        i++;
    j = 0;
    line = malloc(sizeof(char) * (i + 1));
    while (j < i)
    {
        line[j] = stash[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}

static char ft_clean_stach(char *stash) /* After extract the line was read*/
{
    char *new_stash;
    int i;
    int j;

    if (!stash)
        return (ft_free_stash(&stash));
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] = '\n')
        i++;
    j = 0;
    if (!stash[i])
        return (ft_free_stash(&stash));
    while (stash[i + j])
        j++;
    new_stash = malloc(sizeof(char) * (j + i));
    j = 0;
    while(j++ && stash[i + j - 1]) // -1 enleve le retour a la ligne ?, a test
        new_stash[j - 1] = stash[i + j - 1];
     new_stash[j - 1] = '\0';
     free(stash);
     return(new_stash);
}


char    *get_next_line(int fd)
{
    static char *stash[OPEN_MAX];
    char        *line;

    if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
        return(NULL);
    line = NULL;
    // 1. read from fd and att to stash
    read_and_stach(fd, stash);
    if (stash == NULL)
        return (NULL);
    // 2. extract from the line
    line = extract_line(stash[fd]);
    // 3. clean te stash
    stash = ft_clean_stach(stash[fd]);
    return (line);
}

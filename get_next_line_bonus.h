/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:34:33 by marvin            #+#    #+#             */
/*   Updated: 2023/04/16 19:34:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
char    *ft_strjoin_gnl(char *stash, char *buffer);
int     ft_newline(char *stach);
char    *ft_free_stash(char **stash);

#endif
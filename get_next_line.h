/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:49:45 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/23 18:40:58 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *remain, char *buffer);
char	*ft_strdup(char *str);
char	*ft_read_file(int fd, char *remain);
char	*ft_get_line(char *remain);
char	*ft_remove_line(char *remain);

#endif

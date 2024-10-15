/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:20:52 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:20:24 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static	char	*ft_cpystr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	size = ft_strlen(s);
	if (len > size - start)
	{
		len = size - start;
		str = (char *)malloc((size - start) * sizeof(char) + 1);
	}
	else
		str = (char *)malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		str = (char *)malloc(1);
		if (str == NULL)
			return (NULL);
		*str = '\0';
		return (str);
	}
	str = ft_cpystr(s, start, len);
	return (str);
}

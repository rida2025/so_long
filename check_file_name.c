/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:50:08 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:37:42 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

char	check_it(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 3;
	while (str[i])
		i++;
	if (i > 0)
		i--;
	else
		return ('b');
	while (str[i] && i >= size && size > 0)
	{
		i--;
		size--;
	}
	if (ft_strcmp(&str[i], ".ber") != 0)
		return ('b');
	return ('g');
}

char	check_name(char *str)
{
	return (check_it(str));
}

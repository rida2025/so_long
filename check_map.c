/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:41:35 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:36:10 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	check_x_y(char **strs, t_map **info)
{
	int	i;
	int	x1;
	int	x2;

	i = 0;
	x1 = 0;
	x2 = 0;
	while (strs[i])
	{
		x1 = 0;
		while (strs[i][x1])
			x1++;
		x2 = 0;
		while (strs[i + 1] && strs[i + 1][x2])
			x2++;
		if (strs[i + 1] && x1 != x2)
			return ('b');
		i++;
	}
	(*info)->height = i * 50;
	(*info)->width = x1 * 50;
	return ('g');
}

void	insert_info(char c, t_content **info)
{
	if (c == 'P')
		(*info)->player = (*info)->player + 1;
	if (c == 'E')
		(*info)->exit = (*info)->exit + 1;
	if (c == 'C')
		(*info)->collectible = (*info)->collectible + 1;
}

char	check_contant(char **strs, t_content **info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strs[i])
	{
		while (strs[i][j])
		{
			if (strs[i][j] == '1' || strs[i][j] == '0' || strs[i][j] == 'C' \
			|| strs[i][j] == 'E' || strs[i][j] == 'P' || strs[i][j] == 'I')
			{
				insert_info(strs[i][j], info);
				j++;
			}
			else
				return ('b');
		}
		i++;
		j = 0;
	}
	return ('g');
}

char	check_information(t_content **info)
{
	if ((*info)->player != 1)
		return ('b');
	if ((*info)->exit != 1)
		return ('b');
	if ((*info)->collectible < 1)
		return ('b');
	return ('g');
}

char	check_map(char **strs, t_map **info)
{
	t_content	*information;

	information = malloc(sizeof(t_content));
	if (!information)
		return (0);
	information->player = 0;
	information->exit = 0;
	information->collectible = 0;
	(*info)->data = information;
	if (check_x_y(strs, info) == 'b')
		return (free_strings(strs), free(information), 'b');
	if (check_corners(strs) == 'b')
		return (free_strings(strs), free(information), 'b');
	if (check_contant(strs, &information) == 'b')
		return (free_strings(strs), free(information), 'b');
	if (check_information(&information) == 'b')
		return (free_strings(strs), free(information), 'b');
	return ('g');
}

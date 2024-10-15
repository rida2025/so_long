/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_locations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:08:03 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:19:35 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_data(char c, t_map *info, int y, int x)
{
	if (c == 'P')
	{
		info->p_locat->x = x;
		info->p_locat->y = y;
	}
	else if (c == 'I')
	{
		info->e_locat->x = x;
		info->e_locat->y = y;
	}
}

void	get_locations(t_map *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->map[i])
	{
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'P')
			{
				if (!info->p_locat)
					info->p_locat = malloc(sizeof(t_player));
			}
			if (info->map[i][j] == 'I')
			{
				if (!info->e_locat)
					info->e_locat = malloc(sizeof(t_enemy));
			}
			insert_data(info->map[i][j], info, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

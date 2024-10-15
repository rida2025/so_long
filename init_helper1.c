/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:22:30 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:18:30 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_player(t_map *info)
{
	int	img_x;
	int	img_y;

	img_x = 50;
	img_y = 50;
	if (info->timer == 40)
	{
		info->player = mlx_xpm_file_to_image(info->mlx, \
		"img/player1.xpm", &img_x, &img_y);
		if (!info->player)
			exit(1);
	}
	if ((info->timer * 3) == 120)
	{
		info->player = mlx_xpm_file_to_image(info->mlx, \
		"img/player1.2.xpm", &img_x, &img_y);
		if (!info->player)
			exit(1);
	}
}

void	ft_change_coins(t_map *info, int img_y, int img_x)
{
	if (info->timer == 10)
	{
		info->collect = mlx_xpm_file_to_image(info->mlx, \
		"img/coin2.xpm", &img_x, &img_y);
		if (!info->collect)
			exit(1);
	}
	else if (info->timer == 20)
	{
		info->collect = mlx_xpm_file_to_image(info->mlx, \
		"img/coin3.xpm", &img_x, &img_y);
		if (!info->collect)
			exit(1);
	}
	ft_change_coins2(info, img_y, img_x);
}

void	free_everything(t_map *info)
{
	if (info->e_locat)
		free(info->e_locat);
	if (info->p_locat)
		free(info->p_locat);
	if (info->data)
		free(info->data);
	if (info->map)
		free_strings(info->map);
	if (info)
		free(info);
}

void	free_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	check_if_door(t_map *info, char c)
{
	if (c == 'd')
	{
		if (info->map[info->p_locat->y][info->p_locat->x + 1] == 'E' \
		&& info->data->collectible != 0)
			return (1);
	}
	if (c == 'a')
	{
		if (info->map[info->p_locat->y][info->p_locat->x - 1] == 'E' \
		&& info->data->collectible != 0)
			return (1);
	}
	if (c == 's')
	{
		if (info->map[info->p_locat->y + 1][info->p_locat->x] == 'E' \
		&& info->data->collectible != 0)
			return (1);
	}
	if (c == 'w')
	{
		if (info->map[info->p_locat->y - 1][info->p_locat->x] == 'E' \
		&& info->data->collectible != 0)
			return (1);
	}
	return (0);
}

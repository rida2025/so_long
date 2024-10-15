/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:11:47 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 12:37:42 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_movement_right(t_map *info, int img_y, int img_x)
{
	if (info->map[info->e_locat->y][info->e_locat->x + 1] == 'P')
	{
		key_hook(53, info);
	}
	if (info->timer == 20)
	{
		info->enemy = mlx_xpm_file_to_image(info->mlx, \
		"img/enemy_right.xpm", &img_x, &img_y);
		if (!info->enemy)
			exit(1);
		info->map[info->e_locat->y][info->e_locat->x] = '0';
		info->map[info->e_locat->y][info->e_locat->x + 1] = 'I';
		info->e_locat->x += 1;
	}
}

void	enemy_movement_left(t_map *info, int img_y, int img_x)
{
	if (info->map[info->e_locat->y][info->e_locat->x - 1] == 'P')
	{
		key_hook(53, info);
	}
	if (info->timer == 20)
	{
		info->enemy = mlx_xpm_file_to_image(info->mlx, \
		"img/enemy_left.xpm", &img_x, &img_y);
		if (!info->enemy)
			exit(1);
		info->map[info->e_locat->y][info->e_locat->x] = '0';
		info->map[info->e_locat->y][info->e_locat->x - 1] = 'I';
		info->e_locat->x -= 1;
	}
}

void	enemy_movement(t_map *info, int img_y, int img_x)
{
	static int	check;

	if (info->e_locat)
	{
		if (info->map[info->e_locat->y][info->e_locat->x + 1] != '1' \
		&& info->map[info->e_locat->y][info->e_locat->x + 1] != 'C' \
		&& info->map[info->e_locat->y][info->e_locat->x + 1] != 'E' \
		&& check == 0)
			enemy_movement_right(info, img_y, img_x);
		else
			check = 1;
		if (info->map[info->e_locat->y][info->e_locat->x - 1] != '1' \
		&& info->map[info->e_locat->y][info->e_locat->x - 1] != 'C' \
		&& info->map[info->e_locat->y][info->e_locat->x - 1] != 'E' \
		&& check == 1)
			enemy_movement_left(info, img_y, img_x);
		else
			check = 0;
	}
}

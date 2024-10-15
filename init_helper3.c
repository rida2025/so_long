/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:33 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:14:23 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_idie(t_map *info, char c)
{
	if (c == 'd')
	{
		if (info->map[info->p_locat->y][info->p_locat->x + 1] == 'I')
			return (1);
	}
	if (c == 'a')
	{
		if (info->map[info->p_locat->y][info->p_locat->x - 1] == 'I')
			return (1);
	}
	if (c == 's')
	{
		if (info->map[info->p_locat->y + 1][info->p_locat->x] == 'I')
			return (1);
	}
	if (c == 'w')
	{
		if (info->map[info->p_locat->y - 1][info->p_locat->x] == 'I')
			return (1);
	}
	return (0);
}

void	put_images(char c, t_map *info, int y, int x)
{
	if (c == '0')
		mlx_put_image_to_window(info->mlx, info->win, \
	info->floor, (x * 50), (y * 50));
	if (c == '1')
		mlx_put_image_to_window(info->mlx, info->win, \
	info->wall, (x * 50), (y * 50));
	if (c == 'E')
		mlx_put_image_to_window(info->mlx, info->win, \
	info->door, (x * 50), (y * 50));
	if (c == 'C')
		mlx_put_image_to_window(info->mlx, info->win, \
	info->collect, (x * 50), (y * 50));
	if (c == 'P')
		mlx_put_image_to_window(info->mlx, info->win, \
	info->player, (x * 50), (y * 50));
	if (c == 'I')
		mlx_put_image_to_window(info->mlx, info->win, \
	info->enemy, (x * 50), (y * 50));
}

int	key_hook(int keycode, t_map *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->win);
		free_everything(info);
		exit(0);
	}
	if (keycode == 2 || keycode == 124)
		move_to_right(info, 'd', 50, 50);
	if (keycode == 0 || keycode == 123)
		move_to_left(info, 'a', 50, 50);
	if (keycode == 13 || keycode == 126)
		move_to_up(info, 'w', 50, 50);
	if (keycode == 1 || keycode == 125)
		move_to_down(info, 's', 50, 50);
	return (0);
}

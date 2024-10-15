/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:04 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:13:28 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_right(t_map *info, char c, int img_x, int img_y)
{
	int	x;
	int	y;

	x = info->p_locat->x;
	y = info->p_locat->y;
	if (check_if_possible(info, c) == 1 || check_if_door(info, c) == 1)
		return ;
	else
	{
		if (info->map[y][x + 1] == 'E')
			key_hook(53, info);
		if (info->map[y][x + 1] == 'C')
			info->data->collectible -= 1;
		info->map[y][x] = '0';
		info->map[y][x + 1] = 'P';
		info->p_locat->x += 1;
		info->moves += 1;
		ft_putnbr(info->moves);
		info->player = mlx_xpm_file_to_image(info->mlx, \
		"img/player_d.xpm", &img_x, &img_y);
		if (!info->player)
			exit(1);
	}
}

void	move_to_left(t_map *info, char c, int img_x, int img_y)
{
	int	x;
	int	y;

	x = info->p_locat->x;
	y = info->p_locat->y;
	if (check_if_possible(info, c) == 1 || check_if_door(info, c) == 1)
		return ;
	else
	{
		if (info->map[y][x - 1] == 'E')
			key_hook(53, info);
		if (info->map[y][x - 1] == 'C')
			info->data->collectible -= 1;
		info->map[y][x] = '0';
		info->map[y][x - 1] = 'P';
		info->p_locat->x -= 1;
		info->moves += 1;
		ft_putnbr(info->moves);
		info->player = mlx_xpm_file_to_image(info->mlx, \
		"img/player_a.xpm", &img_x, &img_y);
		if (!info->player)
			exit(1);
	}
}

void	move_to_up(t_map *info, char c, int img_x, int img_y)
{
	int	x;
	int	y;

	x = info->p_locat->x;
	y = info->p_locat->y;
	if (check_if_possible(info, c) == 1 || check_if_door(info, c) == 1)
		return ;
	else
	{
		if (info->map[y - 1][x] == 'E')
			key_hook(53, info);
		if (info->map[y - 1][x] == 'C')
			info->data->collectible -= 1;
		info->map[y][x] = '0';
		info->map[y - 1][x] = 'P';
		info->p_locat->y -= 1;
		info->moves += 1;
		ft_putnbr(info->moves);
		info->player = mlx_xpm_file_to_image(info->mlx, \
		"img/player_w.xpm", &img_x, &img_y);
		if (!info->player)
			exit(1);
	}
}

void	move_to_down(t_map *info, char c, int img_x, int img_y)
{
	int	x;
	int	y;

	x = info->p_locat->x;
	y = info->p_locat->y;
	if (check_if_possible(info, c) == 1 || check_if_door(info, c) == 1)
		return ;
	else
	{
		if (info->map[y + 1][x] == 'E')
			key_hook(53, info);
		if (info->map[y + 1][x] == 'C')
			info->data->collectible -= 1;
		info->map[y][x] = '0';
		info->map[y + 1][x] = 'P';
		info->p_locat->y += 1;
		info->moves += 1;
		ft_putnbr(info->moves);
		info->player = mlx_xpm_file_to_image(info->mlx, \
		"img/player_s.xpm", &img_x, &img_y);
		if (!info->player)
			exit(1);
	}
}

int	check_if_possible(t_map *info, char c)
{
	if (c == 'd')
	{
		if (info->map[info->p_locat->y][info->p_locat->x + 1] == '1')
			return (1);
	}
	if (c == 'a')
	{
		if (info->map[info->p_locat->y][info->p_locat->x - 1] == '1')
			return (1);
	}
	if (c == 's')
	{
		if (info->map[info->p_locat->y + 1][info->p_locat->x] == '1')
			return (1);
	}
	if (c == 'w')
	{
		if (info->map[info->p_locat->y - 1][info->p_locat->x] == '1')
			return (1);
	}
	return (0);
}

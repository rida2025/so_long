/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:19:38 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 09:59:56 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_images2(t_map *info, int img_y, int img_x)
{
	info->enemy = mlx_xpm_file_to_image(info->mlx, \
	"img/enemy_right.xpm", &img_x, &img_y);
	if (!info->enemy)
		exit(1);
	info->wall = mlx_xpm_file_to_image(info->mlx, \
	"img/wall.xpm", &img_x, &img_y);
	if (!info->wall)
		exit(1);
	info->door = mlx_xpm_file_to_image(info->mlx, \
	"img/door1.xpm", &img_x, &img_y);
	if (!info->door)
		exit(1);
}

void	change_images(t_map *info, int img_y, int img_x)
{
	info->floor = mlx_xpm_file_to_image(info->mlx, \
	"img/floor.xpm", &img_x, &img_y);
	if (!info->floor)
		exit(1);
	info->collect = mlx_xpm_file_to_image(info->mlx, \
	"img/coin1.xpm", &img_x, &img_y);
	if (!info->collect)
		exit(1);
	if (!info->player)
	{
		info->player = mlx_xpm_file_to_image(info->mlx, \
		"img/player1.xpm", &img_x, &img_y);
		if (!info->player)
			exit(1);
	}
	change_images2(info, img_y, img_x);
}

int	ft_render_base(t_map *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(info->mlx, info->win);
	while (info->map[i])
	{
		while (info->map[i][j])
		{
			put_images(info->map[i][j], info, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_render_the_game(t_map *info)
{
	int		img_x;
	int		img_y;
	char	*str;

	img_x = 50;
	img_y = 50;
	str = ft_itoa(info->moves);
	ft_render_base(info);
	mlx_string_put(info->mlx, info->win, 25, 25, 0x82EEFD, str);
	free(str);
	ft_change_player(info);
	ft_change_coins(info, 50, 50);
	enemy_movement(info, 50, 50);
	info->timer = info->timer + 1;
	if (info->data->collectible == 0)
	{
		info->door = mlx_xpm_file_to_image(info->mlx, \
		"img/door2.xpm", &img_x, &img_y);
		if (!info->door)
			exit(1);
	}
	return (0);
}

void	init_map(t_map *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->width, info->height, "so_long");
	change_images(info, 50, 50);
	mlx_hook(info->win, 17, 0, &close_window, info);
	mlx_key_hook(info->win, key_hook, info);
	mlx_loop_hook(info->mlx, ft_render_the_game, info);
	mlx_loop(info->mlx);
}

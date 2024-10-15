/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:59:19 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:18:20 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *info)
{
	mlx_destroy_window(info->mlx, info->win);
	free_everything(info);
	exit(0);
}

void	ft_change_coins2(t_map *info, int img_y, int img_x)
{
	if (info->timer == 30)
	{
		info->collect = mlx_xpm_file_to_image(info->mlx, \
		"img/coin4.xpm", &img_x, &img_y);
		if (!info->collect)
			exit(1);
	}
	else if (info->timer == 40)
	{
		info->collect = mlx_xpm_file_to_image(info->mlx, \
		"img/coin1.xpm", &img_x, &img_y);
		if (!info->collect)
			exit(1);
		info->timer = 0;
	}
}

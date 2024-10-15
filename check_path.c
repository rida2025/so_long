/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:16:51 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:32:11 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coins_path(char **map, int x, int y)
{
	if (map[y][x] && (map[y][x] == '1' || map[y][x] == 'E' \
	|| map[y][x] == 'M' || map[y][x] == 'I'))
		return ;
	map[y][x] = 'M';
	coins_path(map, x + 1, y);
	coins_path(map, x - 1, y);
	coins_path(map, x, y + 1);
	coins_path(map, x, y - 1);
}

int	check_coins(char **map)
{
	int	i;
	int	j;
	int	coin;

	i = 0;
	j = 0;
	coin = 0;
	while (map[i])
	{
		while (map[i] && map[i][j])
		{
			if (map[i][j] == 'C')
				coin++;
			j++;
		}
		j = 0;
		i++;
	}
	if (coin != 0)
		return (1);
	return (0);
}

int	check_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i] && map[i][j])
		{
			if (map[i][j] == 'E')
				break ;
			j++;
		}
		if (map[i][j] == 'E')
			break ;
		j = 0;
		i++;
	}
	if (map[i][j + 1] != 'M' && map[i][j - 1] != 'M' && map[i + 1][j] != 'M' \
	&& map[i - 1][j] != 'M' && map[i][j + 1] != 'i' && map[i][j - 1] != 'I' \
	&& map[i + 1][j] != 'i' && map[i - 1][j] != 'I')
		return (1);
	return (0);
}

char	**create_cpy(char **map)
{
	char	**cpymap;
	int		i;
	int		x;

	x = 0;
	i = -1;
	while (map[x])
		x++;
	cpymap = (char **)malloc(sizeof(char *) * (x + 1));
	if (!cpymap)
		return (NULL);
	while (map[++i])
	{
		cpymap[i] = ft_strdup(map[i]);
	}
	cpymap[i] = NULL;
	return (cpymap);
}

int	check_path(t_map *info)
{
	t_copymap	*mapcpy;

	mapcpy = malloc(sizeof(t_copymap));
	if (!mapcpy)
		exit(0);
	mapcpy->map = create_cpy(info->map);
	if (!mapcpy->map)
	{
		free(mapcpy);
		exit(0);
	}
	coins_path(mapcpy->map, info->p_locat->x, info->p_locat->y);
	if (check_coins(mapcpy->map) == 1)
		return (free_strings(mapcpy->map), free(mapcpy), 1);
	if (check_exit(mapcpy->map) == 1)
		return (free_strings(mapcpy->map), free(mapcpy), 1);
	return (free_strings(mapcpy->map), free(mapcpy), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:35:05 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 12:45:27 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_helper(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	--i;
	if (str[i] == '\n')
		return (NULL);
	return (ft_split(str, '\n'));
}

char	**ft_read_map(char *str)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**map;

	line = NULL;
	map = NULL;
	tmp = ft_strdup("");
	if (!tmp)
		exit(1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (free(tmp), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line && line[0] == '\n')
			return (free(line), free(tmp), NULL);
		if (!line)
			break ;
		tmp = ft_strjoin(tmp, line);
		free(line);
	}
	map = ft_map_helper(tmp);
	return (free(tmp), map);
}

void	create_struct(t_map **info)
{
	*info = malloc(sizeof(t_map));
	if (!info)
		exit(0);
	(*info)->moves = 0;
	(*info)->timer = 0;
	(*info)->p_locat = NULL;
	(*info)->e_locat = NULL;
	(*info)->player = NULL;
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	*info;

	map = NULL;
	if (argc != 2)
		return (write(1, "Error\n", 6), 0);
	create_struct(&info);
	if (argc == 2)
	{
		if (check_name(argv[1]) == 'b')
			return (free(info), write(1, "Error\n", 6), 0);
		map = ft_read_map(argv[1]);
		if (!map || !*map)
			return (free(map), free(info), write(1, "Error\n", 6), 0);
		if (check_map(map, &info) == 'b')
			return (free(info), write(1, "Error\n", 6), 0);
	}
	info->map = map;
	get_locations(info);
	if (check_path(info) == 1)
		return (free_everything(info), write(1, "Error\n", 6), 0);
	init_map(info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:09:49 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:33:06 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	check_first_line(char **strs)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (strs[0][i])
		i++;
	while (strs[0][x] && strs[0][x] == '1')
		x++;
	if (i != x)
		return ('b');
	return ('g');
}

char	check_last_line(char **strs)
{
	int	z;
	int	i;
	int	x;

	z = 0;
	i = 0;
	x = 0;
	while (strs[z])
		z++;
	z--;
	while (strs[z][i])
		i++;
	while (strs[z][x] && strs[z][x] == '1')
		x++;
	if (i != x)
		return ('b');
	return ('g');
}

char	check_left(char **strs)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (strs[i])
		i++;
	while (strs[y] && strs[y][0] == '1')
		y++;
	if (i != y)
		return ('b');
	return ('g');
}

char	check_right(char **strs)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	while (strs[i][x])
		x++;
	x--;
	while (strs[i] && strs[i][x])
		i++;
	while (strs[y] && strs[y][x] == '1')
		y++;
	if (i != y)
		return ('b');
	return ('g');
}

char	check_corners(char **strs)
{
	if (check_first_line(strs) == 'b' \
	|| check_last_line(strs) == 'b' \
	|| check_left(strs) == 'b' \
	|| check_right(strs) == 'b')
		return ('b');
	return ('g');
}

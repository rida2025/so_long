/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:37:09 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 11:02:49 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_content
{
	int	player;
	int	exit;
	int	collectible;
}	t_content;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_map
{
	int			height;
	int			width;
	int			coins;
	void		*mlx;
	void		*win;
	void		*wall;
	void		*door;
	void		*floor;
	void		*player;
	void		*collect;
	void		*enemy;
	char		**map;
	int			moves;
	int			timer;
	t_enemy		*e_locat;
	t_player	*p_locat;
	t_content	*data;
}	t_map;

typedef struct s_copymap
{
	char	**map;
}	t_copymap;

char	check_name(char *str);
char	check_map(char **strs, t_map **info);
char	check_corners(char **strs);
int		check_path(t_map *info);
void	get_locations(t_map *info);

char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *remain, char *buffer);
char	*ft_strdup(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
void	ft_putnbr(int n);
void	free_strings(char **strs);
void	free_everything(t_map *info);

// helper
void	ft_change_player(t_map *info);
void	ft_change_coins(t_map *info, int img_y, int img_x);
void	free_everything(t_map *info);
void	free_strings(char **strs);
int		check_if_door(t_map *info, char c);
void	move_to_right(t_map *info, char c, int img_x, int img_y);
void	move_to_left(t_map *info, char c, int img_x, int img_y);
void	move_to_up(t_map *info, char c, int img_x, int img_y);
void	move_to_down(t_map *info, char c, int img_x, int img_y);
int		check_if_possible(t_map *info, char c);
int		check_if_idie(t_map *info, char c);
void	put_images(char c, t_map *info, int y, int x);
int		key_hook(int keycode, t_map *info);
int		close_window(t_map *info);
void	ft_change_coins(t_map *info, int img_y, int img_x);
void	ft_change_coins2(t_map *info, int img_y, int img_x);

//mlx
void	init_map(t_map *info);
int		key_hook(int keycode, t_map *info);
void	enemy_movement(t_map *info, int img_y, int img_x);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:09:37 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/06 13:10:27 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE_OF_BOCK 70
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	int		win_height;
	int		win_width;
	int		**w_position;
	int		**c_position;
	int		**e_position;
	int		c_count;
}				t_vars;

typedef struct s_img
{
	void	*img;
	int		img_height;
	int		img_width;
}				t_img;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
char	**getmap(char *path);
void	display_map(char **map);
void	invalid_args(void);
void	display_map(char **map);
void	check_map(char **map);
void	check_intruder(char **map);
void	open_window(char **map);
void	get_info(t_vars *mlx, char **map);
void	put_background(t_vars *mlx);
void	walls_position(t_vars *mlx, char **map);
void	collectibles_position(t_vars *mlx, char **map);
void	put_elements(t_vars *mlx);
void	put_walls(t_vars *mlx);
void	put_mid_wall(t_vars *mlx);
void	put_collectibles(t_vars *mlx);
int		collectibles(t_vars *mlx);
int		standing_right(t_vars *stand);
int		standing_left(t_vars *stand);
int		standing_front(t_vars *mlx);
int		standing_back(t_vars *mlx);
int		running_right(t_vars *stand);
int		running_left(t_vars *stand);
int		running_up(t_vars *mlx);
int		running_down(t_vars *mlx);
int		check_next_position_h(t_vars *mlx, int next_position, char movement);
int		check_next_position_v(t_vars *mlx, int next_position, char movement);
void	check_next_position_4c_v(t_vars *mlx, int next_position, char movement);
void	check_next_position_4c_h(t_vars *mlx, int next_position, char movement);
void	exits_position(t_vars *mlx, char **map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:09:37 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/12 17:49:31 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE_OF_BOCK 50
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
void	display_map(char **map);
char	**getmap(char *path);
void	invalid_args(void);
void	display_map(char **map);
void	check_map(char **map);
void	check_intruder(char **map);
void	open_window(void);
int		standing_right(t_vars *stand);
int		standing_left(t_vars *stand);
int		running_right(t_vars *stand);
int		running_left(t_vars *stand);


#endif

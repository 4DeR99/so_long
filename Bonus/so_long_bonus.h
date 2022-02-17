/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:09:37 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 16:30:10 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define SIZE_OF_BOCK 70
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_img
{
	void	*img;
	int		img_height;
	int		img_width;
}				t_img;

typedef struct s_frame
{
	t_img	corner0;
	t_img	corner1;
	t_img	corner2;
	t_img	corner3;
	t_img	running_down0;
	t_img	running_down1;
	t_img	running_down2;
	t_img	running_down3;
	t_img	running_left0;
	t_img	running_left1;
	t_img	running_left2;
	t_img	running_left3;
	t_img	running_left4;
	t_img	running_left5;
	t_img	running_right0;
	t_img	running_right1;
	t_img	running_right2;
	t_img	running_right3;
	t_img	running_right4;
	t_img	running_right5;
	t_img	running_up0;
	t_img	running_up1;
	t_img	running_up2;
	t_img	running_up3;
	t_img	standing_left0;
	t_img	standing_left1;
	t_img	standing_left2;
	t_img	standing_left3;
	t_img	standing_right0;
	t_img	standing_right1;
	t_img	standing_right2;
	t_img	standing_right3;
	t_img	meat0;
	t_img	meat1;
	t_img	meat2;
	t_img	wall0;
	t_img	wall1;
	t_img	wall2;
	t_img	wall3;
	t_img	background;
	t_img	exit;
	t_img	mid_wall_1;
	t_img	standing_back;
	t_img	standing_front;
	t_img	enemy0;
	t_img	enemy1;
	t_img	enemy2;
}				t_frame;

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
	int		**x_position;
	int		c_count;
	char	**map;
	t_frame	frames;
}				t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
void	one(t_vars *mlx);
void	two(t_vars *mlx);
void	three(t_vars *mlx);
void	four(t_vars *mlx);
void	five(t_vars *mlx);
void	six(t_vars *mlx);
void	seven(t_vars *mlx);
void	eight(t_vars *mlx);
int		count(char **t);
char	*ft_itoa(int nbr);
int		ft_strlen(char *c);
void	ft_putnbr(int n);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s0, char s1);
char	**getmap(char *path);
void	display_map(t_vars *mlx);
void	invalid_args(void);
void	invalid_map(void);
void	display_map(t_vars *mlx);
void	check_map(t_vars *mlx);
void	check_intruder(t_vars *mlx);
void	check_ber(char *ber);
void	open_window(t_vars *mlx);
void	get_info(t_vars *mlx);
void	get_imgs(t_vars *mlx);
void	put_background(t_vars *mlx);
void	walls_position(t_vars *mlx);
void	collectibles_position(t_vars *mlx);
void	put_elements(t_vars *mlx);
void	put_walls(t_vars *mlx);
void	put_mid_wall(t_vars *mlx);
void	put_collectibles(t_vars *mlx);
int		put_exit(t_vars *mlx);
int		collectibles(t_vars *mlx);
int		enemy(t_vars *mlx);
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
int		check_next_position_4exit_h(t_vars *mlx, int next, char movement);
int		check_next_position_4exit_v(t_vars *mlx, int next, char movement);
void	check_next_position_4c_v(t_vars *mlx, int next_position, char movement);
void	check_next_position_4c_h(t_vars *mlx, int next_position, char movement);
int		check_next_position_e(t_vars *mlx, int position, char movement, int i);
int		check_next_position_4exit_e(t_vars *mlx, int next,
			char movement, int i);
int		check_next_position_4c_e(t_vars *mlx, int next, char movement, int i);
void	exits_position(t_vars *mlx);
void	enemy_position(t_vars *mlx);
void	wasted_h(t_vars *mlx, int next_position, char movement);
void	wasted_v(t_vars *mlx, int next_position, char movement);
void	wasted_e_h(t_vars *mlx, int next, char movement, int i);
void	free_all(t_vars *mlx);
void	ft_free(char **str);
int		ft_exit(t_vars *mlx);
#endif
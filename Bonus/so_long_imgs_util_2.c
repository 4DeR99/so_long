/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_imgs_util_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:51:53 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 16:33:54 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	six(t_vars *mlx)
{
	mlx->frames.standing_left0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_left/standing_left0.xpm",
			&mlx->frames.standing_left0.img_width,
			&mlx->frames.standing_left0.img_height);
	mlx->frames.standing_left1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_left/standing_left1.xpm",
			&mlx->frames.standing_left1.img_width,
			&mlx->frames.standing_left1.img_height);
	mlx->frames.standing_left2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_left/standing_left2.xpm",
			&mlx->frames.standing_left2.img_width,
			&mlx->frames.standing_left2.img_height);
	mlx->frames.standing_left3.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_left/standing_left3.xpm",
			&mlx->frames.standing_left3.img_width,
			&mlx->frames.standing_left3.img_height);
	mlx->frames.wall0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/walls/wall0.xpm",
			&mlx->frames.wall0.img_width, &mlx->frames.wall0.img_height);
	mlx->frames.wall1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/walls/wall1.xpm",
			&mlx->frames.wall1.img_width, &mlx->frames.wall1.img_height);
}

void	seven(t_vars *mlx)
{
	mlx->frames.standing_right0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_right/standing_right0.xpm",
			&mlx->frames.standing_right0.img_width,
			&mlx->frames.standing_right0.img_height);
	mlx->frames.standing_right1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_right/standing_right1.xpm",
			&mlx->frames.standing_right1.img_width,
			&mlx->frames.standing_right1.img_height);
	mlx->frames.standing_right2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_right/standing_right2.xpm",
			&mlx->frames.standing_right2.img_width,
			&mlx->frames.standing_right2.img_height);
	mlx->frames.standing_right3.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_right/standing_right3.xpm",
			&mlx->frames.standing_right3.img_width,
			&mlx->frames.standing_right3.img_height);
	mlx->frames.wall2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/walls/wall2.xpm",
			&mlx->frames.wall2.img_width, &mlx->frames.wall2.img_height);
	mlx->frames.wall3.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/walls/wall3.xpm",
			&mlx->frames.wall3.img_width, &mlx->frames.wall3.img_height);
}

void	eight(t_vars *mlx)
{
		mlx->frames.enemy0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/enemy/0X.xpm",
			&mlx->frames.enemy0.img_width, &mlx->frames.enemy0.img_height);
		mlx->frames.enemy1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/enemy/1X.xpm",
			&mlx->frames.enemy1.img_width, &mlx->frames.enemy1.img_height);
		mlx->frames.enemy2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/enemy/2X.xpm",
			&mlx->frames.enemy2.img_width, &mlx->frames.enemy2.img_height);
}

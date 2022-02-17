/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_imgs_util_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:27:49 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:06:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	one(t_vars *mlx)
{
	mlx->frames.corner0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/corners/corner0.xpm", &mlx->frames.corner0.img_width,
			&mlx->frames.corner0.img_height);
	mlx->frames.corner1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/corners/corner1.xpm", &mlx->frames.corner1.img_width,
			&mlx->frames.corner1.img_height);
	mlx->frames.corner2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/corners/corner2.xpm", &mlx->frames.corner2.img_width,
			&mlx->frames.corner2.img_height);
	mlx->frames.corner3.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/corners/corner3.xpm", &mlx->frames.corner3.img_width,
			&mlx->frames.corner3.img_height);
	mlx->frames.standing_back.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_back.xpm",
			&mlx->frames.standing_back.img_width,
			&mlx->frames.standing_back.img_height);
	mlx->frames.standing_front.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/standing_front.xpm",
			&mlx->frames.standing_front.img_width,
			&mlx->frames.standing_front.img_height);
	mlx->frames.mid_wall_1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/mid_wall_1.xpm",
			&mlx->frames.mid_wall_1.img_width,
			&mlx->frames.mid_wall_1.img_height);
}

void	two(t_vars *mlx)
{
	mlx->frames.running_down0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_down/running_down0.xpm",
			&mlx->frames.running_down0.img_width,
			&mlx->frames.running_down0.img_height);
	mlx->frames.running_down1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_down/running_down1.xpm",
			&mlx->frames.running_down1.img_width,
			&mlx->frames.running_down1.img_height);
	mlx->frames.running_down2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_down/running_down2.xpm",
			&mlx->frames.running_down2.img_width,
			&mlx->frames.running_down2.img_height);
	mlx->frames.running_down3.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_down/running_down3.xpm",
			&mlx->frames.running_down3.img_width,
			&mlx->frames.running_down3.img_height);
	mlx->frames.background.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/background.xpm",
			&mlx->frames.background.img_width,
			&mlx->frames.background.img_height);
	mlx->frames.exit.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/exit.xpm",
			&mlx->frames.exit.img_width,
			&mlx->frames.exit.img_height);
}

void	three(t_vars *mlx)
{
	mlx->frames.running_left0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_left/running_left0.xpm",
			&mlx->frames.running_left0.img_height,
			&mlx->frames.running_left0.img_height);
	mlx->frames.running_left1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_left/running_left1.xpm",
			&mlx->frames.running_left1.img_height,
			&mlx->frames.running_left1.img_height);
	mlx->frames.running_left2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_left/running_left2.xpm",
			&mlx->frames.running_left2.img_height,
			&mlx->frames.running_left2.img_height);
	mlx->frames.running_left3.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_left/running_left3.xpm",
			&mlx->frames.running_left3.img_height,
			&mlx->frames.running_left3.img_height);
	mlx->frames.running_left4.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_left/running_left4.xpm",
			&mlx->frames.running_left4.img_height,
			&mlx->frames.running_left4.img_height);
	mlx->frames.running_left5.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_left/running_left5.xpm",
			&mlx->frames.running_left5.img_height,
			&mlx->frames.running_left5.img_height);
}

void	four(t_vars *mlx)
{
	mlx->frames.running_right0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_right/running_right0.xpm",
			&mlx->frames.running_right0.img_width,
			&mlx->frames.running_right0.img_height);
	mlx->frames.running_right1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_right/running_right1.xpm",
			&mlx->frames.running_right1.img_width,
			&mlx->frames.running_right1.img_height);
	mlx->frames.running_right2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_right/running_right2.xpm",
			&mlx->frames.running_right2.img_width,
			&mlx->frames.running_right2.img_height);
	mlx->frames.running_right3.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_right/running_right3.xpm",
			&mlx->frames.running_right3.img_width,
			&mlx->frames.running_right3.img_height);
	mlx->frames.running_right4.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_right/running_right4.xpm",
			&mlx->frames.running_right4.img_width,
			&mlx->frames.running_right4.img_height);
	mlx->frames.running_right5.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_right/running_right5.xpm",
			&mlx->frames.running_right5.img_width,
			&mlx->frames.running_right5.img_height);
}

void	five(t_vars *mlx)
{
	mlx->frames.running_up0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_up/running_up0.xpm",
			&mlx->frames.running_up0.img_width,
			&mlx->frames.running_up0.img_width);
	mlx->frames.running_up1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_up/running_up1.xpm",
			&mlx->frames.running_up1.img_width,
			&mlx->frames.running_up1.img_width);
	mlx->frames.running_up2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_up/running_up2.xpm",
			&mlx->frames.running_up2.img_width,
			&mlx->frames.running_up2.img_width);
	mlx->frames.running_up3.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/running_up/running_up3.xpm",
			&mlx->frames.running_up3.img_width,
			&mlx->frames.running_up3.img_width);
	mlx->frames.meat0.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/meat/meat0.xpm",
			&mlx->frames.meat0.img_width, &mlx->frames.meat0.img_height);
	mlx->frames.meat1.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/meat/meat1.xpm",
			&mlx->frames.meat1.img_width, &mlx->frames.meat1.img_height);
	mlx->frames.meat2.img = mlx_xpm_file_to_image(mlx->mlx,
			"xpm files/meat/meat2.xpm",
			&mlx->frames.meat2.img_width, &mlx->frames.meat2.img_height);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_standing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:52:18 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:06:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	standing_front(t_vars *mlx)
{
	t_img	img;

	img = mlx->frames.standing_front;
	collectibles(mlx);
	enemy(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	return (0);
}

int	standing_back(t_vars *mlx)
{
	t_img	img;

	img = mlx->frames.standing_back;
	collectibles(mlx);
	enemy(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	return (0);
}

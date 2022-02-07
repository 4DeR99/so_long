/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_standing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:52:18 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/20 11:12:18 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	standing_front(t_vars *mlx)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/standing_front.xpm",
			&img.img_width, &img.img_height);
	collectibles(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	return (0);
}

int	standing_back(t_vars *mlx)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/standing_back.xpm",
			&img.img_width, &img.img_height);
	collectibles(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:55:28 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 16:33:59 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_exit(t_vars *mlx)
{
	t_img	img;
	int		i;

	i = 0;
	img = mlx->frames.exit;
	while (mlx->e_position[i])
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
			mlx->e_position[i][0], mlx->e_position[i][1]);
		i++;
	}
	return (0);
}

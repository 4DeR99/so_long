/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_running_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:51:10 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 20:54:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	util(t_vars *mlx, t_img *img, int *i)
{
	if (*i == 0)
		*img = mlx->frames.running_up0;
	if (*i == 1)
		*img = mlx->frames.running_up1;
	if (*i == 2)
		*img = mlx->frames.running_up2;
	if (*i == 3)
		*img = mlx->frames.running_up3;
}

int	running_up(t_vars *mlx)
{
	static int	i;
	static int	j;
	t_img		img;

	if (check_next_position_v(mlx, mlx->player_y - 2, 'U')
		&& check_next_position_4exit_v(mlx, mlx->player_y - 2, 'U'))
		mlx->player_y -= 2;
	check_next_position_4c_v(mlx, mlx->player_y - 2, 'U');
	if (i == 4)
	{
		i = 0;
		j = 0;
	}
	if (j == 10)
	{
		i++;
		j = 0;
	}
	util(mlx, &img, &i);
	collectibles(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	j++;
	return (0);
}

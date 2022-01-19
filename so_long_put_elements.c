/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:06:08 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/19 20:41:47 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_elements(t_vars *mlx)
{
	put_walls(mlx);
	put_mid_wall(mlx);
	// put_collectibles(mlx);
}

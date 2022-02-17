/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:55:19 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:42:41 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_array_int(int **f)
{
	int	i;

	i = 0;
	while (f[i])
	{
		free(f[i]);
		i++;
	}
	free(f);
}

static void	free_array_char(char **f)
{
	int	i;

	i = 0;
	while (f[i])
	{
		free(f[i]);
		i++;
	}
	free(f);
}

void	free_all(t_vars *mlx)
{
	free_array_int(mlx->w_position);
	free_array_int(mlx->c_position);
	free_array_int(mlx->e_position);
	free_array_char(mlx->map);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:29:45 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 16:29:53 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count(char **t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}

int	ft_exit(t_vars *mlx)
{
	free_all(mlx);
	exit(1);
	return (0);
}

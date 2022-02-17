/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:09:03 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/12 15:15:55 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	mlx;
	char	*path;

	if (ac != 2)
		invalid_args();
	path = av[1];
	check_ber(path);
	mlx.map = getmap(path);
	check_map(&mlx);
	open_window(&mlx);
}

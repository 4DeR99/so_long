/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:52:45 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/17 18:13:04 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_vars *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
			write(1, &mlx->map[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	invalid_args(void)
{
	write(1, "-----------SO_LONG-----------\n", 30);
	write(1, "HOW TO : ./so_long + map_file\n", 30);
	exit(1);
}

void	invalid_map(void)
{
	write(1, "Error\n", 6);
	write(1, "Invalid map\n", 12);
}

void	check_ber(char *ber)
{
	int	i;

	i = ft_strlen(ber) - 1;
	if (!(ber[i] == 'r' && ber[i - 1] == 'e'
			&& ber[i - 2] == 'b' && ber[i - 3] == '.'))
	{
		write(1, "Error\n", 6);
		write(1, "Invalid map name\n", 17);
		exit(0);
	}
}

char	*ft_strjoin(char *s0, char s1)
{
	int		c0;
	int		c1;
	int		s0_len;
	char	*re;

	if (!s0)
		s0 = ft_strdup("");
	s0_len = ft_strlen(s0);
	re = (char *)malloc(s0_len + 2);
	if (!re)
		exit(0);
	c0 = -1;
	c1 = 0;
	while (++c0 < s0_len)
		re[c0] = s0[c0];
	re[c0++] = s1;
	re[c0] = '\0';
	return (free(s0), re);
}

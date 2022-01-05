/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:09:03 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/05 15:30:01 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *c)
{
	int	l;

	if (!c)
		return (0);
	l = 0;
	while (c[l])
		l++;
	return (l);
}

char	*ft_strdup(char *s)
{
	char	*re;
	int		len;
	int		i;

	len = ft_strlen(s);
	re = (char *)malloc(len + 1);
	if (!re)
		return (0);
	i = 0;
	while (s[i])
	{
		re[i] = s[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}

char	*get_lines(char *path)
{
	int		fd;
	int		r;
	int		i;
	char	c;
	char	line[100];

	i = 0;
	fd = open(path, O_RDONLY);
	r = 1;
	c = 0;
	while (c != '\n' && r == 1)
	{
		r = read(fd, &c, 1);
		if (c != '\n')
			line[i++] = c;
	}
	line[i] = '\0';
	close(fd);
	return (ft_strdup(line));
}

int	tab_allocation(char *path)
{
	int		fd;
	int		count;
	int		r;
	char	c;

	count = 0;
	r = 1;
	fd = open(path, O_RDONLY);
	c = 0;
	while (r == 1)
	{
		r = read(fd, &c, 1);
		if (r == 0)
			c = 0;
		if (c == '\n')
			count++;
	}
	count++;
	return (count);
}

char	**getmap(char *path)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(tab_allocation(path) * sizeof(char *));
	while (map[i])
		map[i++] = get_lines(path);
	return (map);
}

void	display_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
			write(1, &map[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**map;
	char	*path;

	if (ac != 2)
	{
		printf("-----------SO_LONG-----------\n");
		printf("HOW TO : ./so_long + map_file\n");
		exit(1);
	}
	path = av[1];
	map = getmap(path);
	display_map(map);
}

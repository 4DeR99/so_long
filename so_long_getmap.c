/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_getmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:44:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/11 16:11:08 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strlen(char *c)
{
	int	l;

	if (!c)
		return (0);
	l = 0;
	while (c[l])
		l++;
	return (l);
}

static char	*ft_strdup(char *s)
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

static char	*get_lines(char *path, int fd)
{
	int		r;
	int		i;
	char	c;
	char	line[1000];

	i = 0;
	r = 1;
	c = 0;
	while (c != '\n' && r == 1)
	{
		r = read(fd, &c, 1);
		if (c != '\n')
			line[i++] = c;
	}
	line[i] = '\0';
	return (ft_strdup(line));
}

static int	tab_allocation(char *path)
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
	close(fd);
	return (count);
}

char	**getmap(char *path)
{
	char	**map;
	int		fd;
	int		tab_len;
	int		i;

	i = 0;
	tab_len = tab_allocation(path);
	map = (char **)malloc((tab_len + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	while (tab_len-- > 0)
		map[i++] = get_lines(path, fd);
	map[i] = NULL;
	close(fd);
	if (!map || !*map)
		exit(0);
	return (map);
}

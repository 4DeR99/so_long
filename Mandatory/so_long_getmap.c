/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_getmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:44:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/17 18:12:50 by moulmado         ###   ########.fr       */
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

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	re = (char *)malloc(len + 1);
	if (!re)
		exit(0);
	i = 0;
	while (s[i])
	{
		re[i] = s[i];
		i++;
	}
	re[i] = '\0';
	if (*s)
		free(s);
	return (re);
}

static char	*get_lines(int fd, char *line)
{
	int		r;
	int		i;
	char	c;
	int		count;

	count = 0;
	i = 0;
	r = 1;
	c = 0;
	while (c != '\n' && r == 1)
	{
		r = read(fd, &c, 1);
		if (r == 1)
			count++;
		if (c != '\n' && r != 0)
		{
			line = ft_strjoin(line, c);
			i++;
		}
	}
	if (line)
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
	read(fd, &c, 1);
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
	close(fd);
	return (count);
}

char	**getmap(char *path)
{
	static char	*line;
	char		**map;
	int			fd;
	int			tab_len;
	int			i;

	i = 0;
	tab_len = tab_allocation(path);
	map = (char **)malloc((tab_len + 1) * sizeof(char *));
	if (!map)
		exit(0);
	fd = open(path, O_RDONLY);
	while (i < tab_len)
		map[i++] = get_lines(fd, line);
	map[i] = NULL;
	if (count(map) != i || count(map) < 3)
	{
		ft_free(map);
		invalid_map();
		exit(0);
	}
	close(fd);
	if (!map || !*map)
		exit(0);
	return (map);
}

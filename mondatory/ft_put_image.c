/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:21:18 by zel-hach          #+#    #+#             */
/*   Updated: 2022/03/22 15:37:29 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx.h"
#include"so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	print_image(t_vars *args)
{
	int	t[2];

	args->img.wall = mlx_xpm_file_to_image(args->mlx,
			"images/wall.xpm", &t[0], &t[1]);
	args->img.player = mlx_xpm_file_to_image(args->mlx,
			"images/princess.xpm", &t[0], &t[1]);
	args->img.coll = mlx_xpm_file_to_image(args->mlx,
			"images/rose (1).xpm", &t[0], &t[1]);
	args->img.home = mlx_xpm_file_to_image(args->mlx,
			"images/home.xpm", &t[0], &t[1]);
}

void	ft_put_image(t_vars *args)
{
	int	i;
	int	j;

	i = -1;
	print_image(args);
	while (args->arr[++i])
	{
		j = 0;
		while (args->arr[i][j])
		{
			map_to_image(args, i, j);
			j++;
		}
	}
}

char	*get_next_line(int fd)
{
	char	tmp[800000];
	char	buff[0];
	char	*line;
	int		i;

	i = 0;
	tmp[0] = '\0';
	while (read(fd, buff, 1))
	{
		tmp[i++] = buff[0];
		tmp[i + 1] = '\0';
	}
	if (tmp[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

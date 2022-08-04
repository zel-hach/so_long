/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afficher_char_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:33:25 by zel-hach          #+#    #+#             */
/*   Updated: 2022/08/04 22:09:42 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"

static int	ft_lenght(int n)
{
	int	c;

	c = 0;
	if (n <= 0)
		c = 1;
	while (n != 0)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int			j;
	char		*ptr;
	long int	i;

	i = n;
	j = ft_lenght(i);
	ptr = malloc(sizeof(char) * j + 1);
	if (!ptr)
		return (NULL);
	ptr[j--] = '\0';
	if (i < 0)
	{
		i = i * (-1);
		ptr[0] = '-';
	}
	if (i == 0)
	{
		ptr[0] = '0';
	}
	while (i > 0)
	{
		ptr[j--] = 48 + (i % 10);
		i = i / 10;
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char	tmp[800000];
	char	buff[0];
	char	*line;
	int		i;

	i = 0;
	tmp[0] = '\0';
	while (read(fd, buff, 1) == 1)
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

int	ft_count_move(int keycode, t_vars *data)
{
	if (keycode == 2)
		ft_move_x_y_bonus(data, data->point.x1, data->point.y1 + 1);
	if (keycode == 0)
		ft_move_x_y_bonus(data, data->point.x1, data->point.y1 - 1);
	if (keycode == 1)
		ft_move_x_y_bonus(data, data->point.x1 + 1, data->point.y1);
	if (keycode == 13)
		ft_move_x_y_bonus(data, data->point.x1 - 1, data->point.y1);
	if (keycode == 53)
	{
		ft_destroy_bonus(data);
		end_free(data);
		exit(0);
	}
	return (1);
}

int	ft_strrchr(char *s, char *c)
{
	int	len;
	int	lenc;

	len = ft_strlen(s);
	lenc = ft_strlen(c);
	lenc--;
	len--;
	while (lenc >= 0)
	{
		if (s[len] == c[lenc])
		{
			len--;
			lenc--;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

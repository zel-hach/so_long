/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:21:10 by zel-hach          #+#    #+#             */
/*   Updated: 2022/08/04 22:24:37 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	move(t_vars *args)
{
	int	i;
	int	j;

	i = -1;
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

void	ft_move_x_y(t_vars *data, int t, int z)
{
	if (data->arr[t][z] == '0' || data->arr[t][z] == 'C')
	{
		data->arr[data->point.x1][data->point.y1] = '0';
		data->arr[t][z] = 'P';
		mlx_clear_window(data->mlx, data->win);
		move(data);
	}
	if ((data->arr[t][z] == 'E'
		&& ft_strchr(&(data->arr[0])) == 0))
	{
		ft_destroy(data);
		end_free(data);
		ft_putstr("\e[42m");
		ft_putstr("succes,bravo! 😁");
		exit(0);
	}
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

void	check_map(char *str)
{
	int		fd;
	t_vars	*args;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_putstr("fichier n'existe pas");
	else
	{
		args = malloc(sizeof(t_vars));
		line = get_next_line(fd);
		if (!line)
		{
			ft_putstr("map is vide");
			free(args);
		}
		if (check_empty_space(line) == 1)
			put_check_erreur(args);
		else
		{
			args->arr = ft_split(line, '\n');
			free(line);
			afficher_window(args);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strrchr(argv[1], ".ber") == 1)
		{
			check_map(argv[1]);
		}
		else
			ft_putstr("l 'extention de fichier n'est pas .ber");
	}
	else
		ft_putstr("le nembre des arguments > 2");
	return (0);
}

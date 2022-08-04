/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:36:15 by zel-hach          #+#    #+#             */
/*   Updated: 2022/08/04 22:10:27 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long_bonus.h"

void	map_to_image(t_vars *args, int i, int j)
{
	if (args->arr[i][j] == '1')
		mlx_put_image_to_window(args->mlx,
			args->win, args->img.wall, j * 32, i * 32);
	if (args->arr[i][j] == 'P')
	{
		mlx_put_image_to_window(args->mlx,
			args->win, args->img.player, j * 32, i * 32);
		args->point.x1 = i;
		args->point.y1 = j;
	}
	if (args->arr[i][j] == 'C')
		mlx_put_image_to_window(args->mlx,
			args->win, args->img.coll, j * 32, i * 32);
	if (args->arr[i][j] == 'E')
		mlx_put_image_to_window(args->mlx,
			args->win, args->img.home, j * 32, i * 32);
	if (args->arr[i][j] == 'N')
		mlx_put_image_to_window(args->mlx,
			args->win, args->img.enemi, j * 32, i * 32);
}

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

int	funct_ptr(void *data)
{
	static int	i;
	t_vars		*args;

	args = data;
	mlx_clear_window(args->mlx, args->win);
	move(args);
	ft_image_to_enemi(args, &i);
	i++;
	if (i == 60)
		i = 0;
	return (0);
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
			afficher_window_bonus(args);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strrchr(argv[1], ".ber") == 1)
			check_map(argv[1]);
		else
			ft_putstr("l 'extention de fichier n'est pas .ber");
	}
	else
		ft_putstr("le nembre des arguments > 2");
	return (0);
}

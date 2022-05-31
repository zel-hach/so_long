/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afficher_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:07:20 by zel-hach          #+#    #+#             */
/*   Updated: 2022/03/22 17:44:16 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

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
}

int	ft_close(int keycode, void *vars)
{
	t_vars	*data;

	data = vars;
	if (keycode == 2)
		ft_move_x_y(data, data->point.x1, data->point.y1 + 1);
	if (keycode == 0)
		ft_move_x_y(data, data->point.x1, data->point.y1 - 1);
	if (keycode == 1)
		ft_move_x_y(data, data->point.x1 + 1, data->point.y1);
	if (keycode == 13)
		ft_move_x_y(data, data->point.x1 - 1, data->point.y1);
	if (keycode == 53)
	{
		end_free(data);
		ft_destroy(data);
		exit(0);
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars = 0;
	keycode = 0;
	exit(0);
}

void	put_check_erreur(t_vars *args)
{
	ft_putstr("il y 'a quelque erreur dans le MAP");
	free(args);
}

void	afficher_window(t_vars *args)
{
	while (args->arr[args->height])
	{
		args->width = 0;
		while (args->arr[args->height][args->width])
		{
			args->width++;
		}
		args->height++;
	}
	if ((check_len(args) == 1)
		|| (check_erreur_char(args) == 1)
		|| (check_erreur_number(args) == 1) || (check_erreur(args) == 1))
		put_check_erreur(args);
	else
	{
		args->mlx = mlx_init();
		args->win = mlx_new_window(args->mlx,
				args->width * 32, args->height * 32, "so_long");
		ft_put_image(args);
		mlx_hook(args->win, 02, 0L, ft_close, (void *)args);
		mlx_hook(args->win, 17, 0, key_hook, (void *)args);
		mlx_loop(args->mlx);
	}
}

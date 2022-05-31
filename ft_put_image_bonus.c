/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:24:02 by zel-hach          #+#    #+#             */
/*   Updated: 2022/03/22 19:33:33 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx.h"
#include"so_long.h"

int	ft_close_bonus(int keycode, void *vars)
{
	t_vars		*data;

	data = vars;
	ft_count_move(keycode, data);
	return (0);
}

int	key_hook_bonus(int keycode, t_vars *vars)
{
	vars = 0;
	keycode = 0;
	exit(0);
}

void	print_image(t_vars *args)
{
	int	t[2];

	args->img.wall = mlx_xpm_file_to_image(args->mlx,
			"images/wall.xpm",
			&t[0], &t[1]);
	args->img.player = mlx_xpm_file_to_image(args->mlx,
			"images/princess.xpm",
			&t[0], &t[1]);
	args->img.coll = mlx_xpm_file_to_image(args->mlx,
			"images/rose (1).xpm",
			&t[0], &t[1]);
	args->img.home = mlx_xpm_file_to_image(args->mlx,
			"images/home.xpm",
			&t[0], &t[1]);
	args->img.enemi = mlx_xpm_file_to_image(args->mlx,
			"images/bee.xpm",
			&t[0], &t[1]);
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

void	afficher_window_bonus(t_vars *args)
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
	if (check_len(args) == 1
		|| (check_erreur_char(args) == 1) || (check_erreur_number(args) == 1)
		|| (check_erreur(args) == 1))
		put_check_erreur(args);
	else
	{
		args->mlx = mlx_init();
		args->win = mlx_new_window(args->mlx,
				args->width * 32, args->height * 32, "so_long");
		ft_put_image(args);
		mlx_hook(args->win, 02, 0L, ft_close_bonus, (void *)args);
		mlx_hook(args->win, 17, 0, key_hook_bonus, (void *)args);
		mlx_loop_hook(args->mlx, funct_ptr, (void *)args);
		mlx_loop(args->mlx);
	}
}

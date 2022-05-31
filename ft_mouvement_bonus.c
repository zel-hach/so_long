/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvement_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:30:54 by zel-hach          #+#    #+#             */
/*   Updated: 2022/03/22 18:46:27 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	put_check_erreur(t_vars *args)
{
	ft_putstr("il y 'a quelque erreur dans le MAP");
	free(args);
}

void	ft_image_to_enemi(t_vars *args, int *i)
{
	int	t[2];

	if (*i == 0)
		args->img.enemi = mlx_xpm_file_to_image(args->mlx,
				"images/bee0.xpm", &t[0], &t[1]);
	else if (*i == 10)
		args->img.enemi = mlx_xpm_file_to_image(args->mlx,
				"images/bee1.xpm", &t[0], &t[1]);
	else if (*i == 20)
		args->img.enemi = mlx_xpm_file_to_image(args->mlx,
				"images/bee2.xpm", &t[0], &t[1]);
	else if (*i == 30)
		args->img.enemi = mlx_xpm_file_to_image(args->mlx,
				"images/bee8.xpm", &t[0], &t[1]);
}

void	ft_count_mouvement(t_vars *data)
{
	static int	count;

	count++;
	mlx_clear_window(data->mlx, data->win);
	move(data);
	ft_putstr("le nombre de mouvement est: ");
	ft_putstr(ft_itoa(count));
	ft_putstr("\n");
}

void	ft_move_x_y_bonus(t_vars *data, int t, int z)
{
	if (data->arr[t][z] == '0' || data->arr[t][z] == 'C')
	{
		data->arr[data->point.x1][data->point.y1] = '0';
		data->arr[t][z] = 'P';
		ft_count_mouvement(data);
	}
	if ((data->arr[t][z] == 'E'
		&& ft_strchr(&(data->arr[0])) == 0))
	{
		ft_destroy_bonus(data);
		end_free(data);
		ft_putstr("\e[42m");
		ft_putstr("succes,bravo! 😁");
		exit(0);
	}
	if (data->arr[t][z] == 'N')
	{
		ft_destroy_bonus(data);
		end_free(data);
		ft_putstr("\e[41m");
		ft_putstr("tu as fait une erreur😧");
		exit(0);
	}
}

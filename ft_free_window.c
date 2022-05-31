/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:34:59 by zel-hach          #+#    #+#             */
/*   Updated: 2022/03/22 15:41:15 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	ft_destroy(t_vars *data)
{
	mlx_destroy_image(data->mlx, data->img.coll);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.home);
	mlx_destroy_window(data->mlx, data->win);
}

void	end_free(t_vars *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->arr[i]);
		i++;
	}
}

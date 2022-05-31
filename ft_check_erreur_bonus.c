/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_erreur_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:33:47 by zel-hach          #+#    #+#             */
/*   Updated: 2022/03/22 17:16:12 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	check_len(t_vars *data)
{
	while (data->arr[data->point.x1])
	{
		if (ft_strlen(data->arr[0]) != ft_strlen(data->arr[data->point.x1]))
		{
			return (1);
		}
		data->point.x1++;
	}
	return (0);
}

int	check_erreur(t_vars *data)
{
	int	i;
	int	d;
	int	k;
	int	j;

	j = 0;
	i = 0;
	d = 0;
	k = 0;
	while (data->arr[j])
		j++;
	while (data->arr[k][d])
		d++;
	if (ft_strchr1(data->arr[0]) == 0 || ft_strchr1(data->arr[j - 1]) == 0)
		return (1);
	while (data->arr[k] && data->arr[k][i])
	{
		if (data->arr[k][0] != '1' || data->arr[k][d - 1] != '1')
			return (1);
		k++;
	}
	return (0);
}

int	check_erreur_number(t_vars *data)
{
	int	resulta;
	int	resulta1;
	int	resulta2;
	int	l;
	int	j;

	resulta = 0;
	resulta1 = 0;
	resulta2 = 0;
	l = 0;
	j = 0;
	while (data->arr[j])
		j++;
	while (l < j)
	{
		resulta += ft_count((data->arr[l]), 'C');
		resulta1 += ft_count((data->arr[l]), 'P');
		resulta2 += ft_count((data->arr[l]), 'E');
		l++;
	}
	if (resulta < 1 || resulta1 != 1 || resulta2 < 1)
		return (1);
	return (0);
}

int	check_erreur_char(t_vars *data)
{
	int	l;
	int	i;

	l = 0;
	while (data->arr[l])
	{
		i = 0;
		while (data->arr[l][i])
		{
			if (data->arr[l][i] == 'E' || data->arr[l][i] == 'C'
				|| data->arr[l][i] == 'P' || data->arr[l][i] == '0'
				|| data->arr[l][i] == '1' || data->arr[l][i] == 'N')
				i++;
			else
				return (1);
		}
		l++;
	}
	return (0);
}

int	check_empty_space(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if ((line[j] == '\n' && line[j + 1] == '\n')
			|| line[0] == '\n' || (line[j] == '\n' && line[j + 1] == '\0'))
			return (1);
		j++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:35:10 by zel-hach          #+#    #+#             */
/*   Updated: 2022/08/04 22:35:11 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	ft_strchr(char **save)
{
	int	i;
	int	j;

	i = 0;
	if (!(**save))
		return (-1);
	while (save[i])
	{
		j = 0;
		while (save[i][j])
		{
			if (save[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strchr1(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (-1);
	while (save[i])
	{
		if (save[i] == 'C')
			return (1);
		if (save[i] == '0' || save[i] == 'E' || save[i] == 'C')
			return (0);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t  j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_count(char *save, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!save)
		return (-1);
	while (save[i])
	{
		if (save[i] == c)
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

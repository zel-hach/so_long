/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:33:42 by zel-hach          #+#    #+#             */
/*   Updated: 2022/08/04 22:10:35 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

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

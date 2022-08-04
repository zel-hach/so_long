/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:09:28 by zel-hach          #+#    #+#             */
/*   Updated: 2022/08/04 22:09:29 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_image
{
	void	*player;
	void	*wall;
	void	*coll;
	void	*home;
	void	*enemi;
}	t_image;

typedef struct s_point
{
	int	x1;
	int	y1;
}	t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**arr;
	t_image	img;
	t_point	point;
	int		width;
	int		height;
}	t_vars;

int		ft_count(char *save, char c);
void	ft_putstr(char *s);
int		ft_strlen(char *str);
int		ft_strchr(char **save);
int		ft_strchr1(char *save);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		check_erreur_char(t_vars *data);
int		check_erreur_number(t_vars *data);
int		check_len(t_vars *data);
int		main(int argc, char **argv);
void	afficher_window(t_vars *args);
void	ft_put_image(t_vars *args);
int		key_hook(int keycode, t_vars *vars);
int		ft_close(int keycode, void *vars);
void	move(t_vars *args);
void	ft_move_x_y(t_vars *data, int t, int z);
int		check_empty_space(char *line);
char	*ft_itoa(int n);
void	map_to_image(t_vars *args, int i, int j);
int		funct_ptr(void *data);
void	ft_image_to_enemi(t_vars *args, int *i);
void	print_image(t_vars *args);
int		ft_count_move(int keycode, t_vars *data);
int		check_erreur(t_vars *data);
int		ft_strrchr(char *s, char *c);
void	check_map(char *str);
void	ft_destroy(t_vars *data);
void	afficher_window_bonus(t_vars *args);
int		key_hook_bonus(int keycode, t_vars *vars);
int		ft_close_bonus(int keycode, void *vars);
void	ft_destroy_bonus(t_vars *data);
void	ft_move_x_y_bonus(t_vars *data, int t, int z);
void	end_free(t_vars *data);
void	put_check_erreur(t_vars *args);

#endif
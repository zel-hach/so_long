SO_LONG = so_long
SO_LONG_BONUS = so_long_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS =  -lmlx -framework OpenGL -framework AppKit

SRC = mondatory/so_long.c mondatory/ft_check_erreur.c mondatory/so_long_utils.c mondatory/ft_read.c mondatory/ft_put_image.c mondatory/ft_afficher_window.c mondatory/ft_free_window.c
SRC_BONUS = bonus/so_long_bonus.c bonus/ft_check_erreur_bonus.c bonus/so_long_utils_bonus.c bonus/ft_read_bonus.c bonus/ft_put_image_bonus.c  bonus/ft_afficher_char_bonus.c bonus/ft_mouvement_bonus.c bonus/ft_free_window_bonus.c

OBJECTS = $(SRC:.c=.o)
OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = mondatory/so_long.h bonus/so_long_bonus.h

all: $(SO_LONG)
bonus:$(SO_LONG_BONUS)

$(SO_LONG): $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) $(MLXFLAGS) -o $(SO_LONG)
$(SO_LONG_BONUS):$(OBJECTS_BONUS)
		$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJECTS_BONUS) -o $(SO_LONG_BONUS)
%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm -rf $(SO_LONG) $(SO_LONG_BONUS)

re: fclean all
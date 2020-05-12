# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suzie <suzie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:35:27 by grochefo          #+#    #+#              #
#    Updated: 2020/05/12 21:12:09 by suzie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

FLAGS = -Wall -Werror -Wextra

LIBS = libmlx.a cub3dlib.a

EVENTS = event.c \
		 ft_close_window.c \
		 move_back.c \
		 move_forward.c \
		 move_left.c \
		 move_right.c \
		 turning_cam.c

INIT = init_color.c \
	   init_data_map.c \
	   init_position.c \
	   init_resolution.c \
	   init_sprite.c \
	   init_texture.c \
	   init_to_default.c
	   
LIBFT =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memset.c \
		ft_memdel.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoinnplus.c \
		ft_strjoinplus.c \
		ft_strlen.c \
		ft_strlenn.c \
		ft_strncat.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnew.c \
		get_next_line.c

PARSING_DATA = line_to_tab.c \
			   parsing_data.c

RAYCASTING = ft_calcul_vec_dist.c \
			 ft_calcul_wall.c \
			 ft_raycasting_sprite.c \
			 ft_raycasting.c

SRCS = ft_error.c \
	   ft_exit_cub.c \
	   ft_put_image.c

CUB3D_INC = cub3d.h libft/libft.h

ALL_SRCS = $(addprefix events/,$(EVENTS)) $(addprefix init/,$(INIT)) \
		   $(addprefix libft/,$(LIBFT)) $(addprefix parsing_data/,$(PARSING_DATA)) \
		   $(addprefix raycasting/,$(RAYCASTING)) $(addprefix srcs/,$(SRCS))

OBJ = $(EVENTS:.c=.o) $(INIT:.c=.o) $(LIBFT:.c=.o) $(PARSING_DATA:.c=.o) \
		$(RAYCASTING:.c=.o) $(SRCS:.c=.o)
.PHONY : clean fclean re all
.SILENT : clean fclean re all cub3dlib $(NAME)
all: $(NAME)

$(NAME) : cub3dlib $(ALL_SRCS) $(CUB3D_INC)
		echo "\033[1;33mCUB3D compiling...\033[0m"
		gcc -o cub3d cub3d.c cub3dlib.a libmlx.a -Wall -Werror -Wextra -lXext -lX11 -lm -lbsd
		echo "\033[32mCUB3D compilation over.\033[0m"

cub3dlib :
	gcc $(FLAGS) -c $(ALL_SRCS) -I./
	ar rc cub3dlib.a $(OBJ)
	ranlib cub3dlib.a
	rm -f $(OBJ)

clean :
	echo "\033[1;33mCleaning CUB3D...\033[0m"
	rm -f $(NAME)
	rm -f cub3dlib.a
	echo "\033[0;35m$(NAME) executable removed.\033[0m"

fclean: clean
		echo "\033[0;35m$(NAME) executable removed.\033[0m"
re: fclean all

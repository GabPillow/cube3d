# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suzie <suzie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:35:27 by grochefo          #+#    #+#              #
#    Updated: 2020/02/23 12:59:05 by suzie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CUB3D_FILES_C = libft/ft_strjoinplus.c \
				libft/get_next_line.c \
				libft/ft_strdup.c \
				libft/ft_strcpy.c \
				libft/ft_strnew.c \
				libft/ft_calloc.c \
				libft/ft_strlen.c \
				libft/ft_strcat.c \
				libft/ft_memdel.c \
				libft/ft_strdel.c \
				libft/ft_memcpy.c \
				libft/ft_bzero.c \
				libft/ft_memset.c \
				libft/ft_strncpy.c \
				libft/ft_strndup.c \
				libft/ft_strjoinnplus.c \
				libft/ft_strlenn.c \
				libft/ft_strncat.c \
				parsing_data/parsing_data.c \
				parsing_data/line_to_tab.c \
				parsing_data/init_data.c
				# cub3d.c
				# ft_raycasting.c
				# events/move_back.c
				# events/move_forward.c
				# events/move_left.c
				# events/move_right.c
				# events/turning_cam.c

CUB3D_INC = cub3d.h

.PHONY : clean fclean re all
.SILENT : clean fclean re all $(NAME)
all: $(NAME)

$(NAME) : $(CUB3D_FILES_C) $(CUB3D_INC)
		echo "\033[1;33mCUB3D compiling...\033[0m"
		gcc -Wall -Wextra -Werror main.c $(CUB3D_FILES_C)
		echo "\033[32mCUB3D compilation over.\033[0m"
clean :
	echo "\033[1;33mCleaning CUB3D...\033[0m"
	rm -f $(NAME)
	echo "\033[0;35m$(NAME) executable removed.\033[0m"

fclean: clean
			echo "\033[0;35m$(NAME) executable removed.\033[0m"
re: fclean all

#  -I minilibx -L minilibx -lmlx -framework
# 		OpenGL -framework AppKit 

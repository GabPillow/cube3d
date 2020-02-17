# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:35:27 by grochefo          #+#    #+#              #
#    Updated: 2020/02/17 15:45:30 by grochefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CUB3D_FILES_C =	cub3d.c \
				events/move_back.c \
				events/move_forward.c \
				events/move_left.c \
				events/move_right.c \
				events/turning_cam.c

CUB3D_INC = cub3d.h

.PHONY : clean fclean re all
.SILENT : clean fclean re all $(NAME)
all: $(NAME)

$(NAME) : $(CUB3D_FILES_C) $(CUB3D_INC)
		echo "\033[1;33mCUB3D compiling...\033[0m"
		gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework \
		OpenGL -framework AppKit $(CUB3D_FILES_C)
		echo "\033[32mCUB3D compilation over.\033[0m"
clean :
	echo "\033[1;33mCleaning CUB3D...\033[0m"
	rm -f $(NAME)
	echo "\033[0;35m$(NAME) executable removed.\033[0m"

fclean: clean
			echo "\033[0;35m$(NAME) executable removed.\033[0m"
re: fclean all
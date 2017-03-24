# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 17:47:08 by ykondrat          #+#    #+#              #
#    Updated: 2017/03/14 17:49:59 by ykondrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = wolf_error.c\
	  wolf_get_map.c\
	  wolf_key.c\
	  wolf_main.c\
	  wolf_putstr.c\
	  wolf_set_texture.c\
	  wolf_start_draw.c\
	  wolf_upload_data.c

LIB = -L ./libft/ -lft

SRC_O = $(SRC:.c=.o)

INC = wolf_header.h

INC_LIB = libft/libft.h

FLAG = -Wall -Werror -Wextra

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
	
$(NAME): $(SRC_O) $(INC_LIB) $(INC)
	@echo "\033[33mCompiling started..."
	@make -C ./libft/
	@echo "\033[33mCompiling project...\033[0m"
	gcc -o $(NAME) $(SRC_O) $(LIB) $(MLX_FLAG)
	@echo "\033[32;01mSuccess!!!"
	@echo "\033[32;05mReady to go =)"

%.o: %.c
	@gcc $(FLAG) -I $(INC) -c $<

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	rm -f $(SRC_O)
	@make clean -C ./libft/

fclean: clean
	@echo "\033[31mRemoving executable\033[0m"
	rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:24:46 by pdeson            #+#    #+#              #
#    Updated: 2024/04/17 10:24:57 by pdeson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
CC 			= @cc
CFLAGS 		= -Werror -Wall -Wextra -g3
MFLAGS 		= -lmlx -lXext -lX11
MLX_LIB 	= minilibx/libmlx_Linux.a
LIBFT_LIB 	= libft/libft.a
HEADERS		= so_long.h
SRCES_PATH	= srces/
OBJS_PATH	= .objs/

SRC			=	so_long.c verifs.c ft_errors.c ft_exit.c game_controls.c game_init.c \
				so_long_utils.c

SRCES		= $(addprefix $(SRCES_PATH), $(SRC))

# Generate a list of object files
LIST_OBJS	= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJS_PATH), $(LIST_OBJS))

all: $(NAME)

# link with the required internal API
$(NAME): $(OBJ)
	@make -C minilibx/ all > /dev/null 2>&1
	@echo "✅\tLibrary minilibx created"
	@make -C libft/ all > /dev/null
	@echo "✅\tLibrary libft created"
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME) > /dev/null
	@echo "🏁\tCompilation made\n"

clean:
	@make -C minilibx/ clean  > /dev/null
	@make -C libft/ clean  > /dev/null
	@rm -f $(OBJS_PATH)  > /dev/null
	@echo "❌\tObject files erased!"

fclean: clean
#	make -C minilibx/ fclean
	@make -C libft/ fclean  > /dev/null
	@rm -f $(NAME)  > /dev/null
	@echo "❌\tProject So_long erased!"

re: fclean all

.PHONY: all clean fclean re

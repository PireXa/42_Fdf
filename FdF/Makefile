# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 16:01:05 by fde-albe          #+#    #+#              #
#    Updated: 2022/04/20 16:08:02 by fde-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= controls.c calc_mesh.c connector.c designer.c \
		  const_calc.c fdf.c get_next_line_utils.c \
		  get_next_line.c valuescount.c ft_isspace.c \
		  ctrl_handlers.c ctrl_handlers2.c \

OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= fdf

all:		$(NAME)

objs/%.o: srcs/%.c
			@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): 	$(OBJS)
			@cc $(OBJS) libft.a -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

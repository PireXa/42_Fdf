# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 16:01:05 by fde-albe          #+#    #+#              #
#    Updated: 2022/04/22 17:11:02 by fde-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= controls.c calc_mesh.c connector.c designer.c \
		  const_calc.c fdf.c get_next_line_utils.c \
		  get_next_line.c valuescount.c ft_isspace.c \
		  ctrl_handlers.c ctrl_handlers2.c calc_color.c \
		  initializers.c ft_atoi.c ft_split.c ft_bzero.c \
		  ft_memset.c ft_calloc.c ft_itoa.c ft_printf.c \
		  ft_putchar.c ft_puthex.c ft_puthexup.c ft_putptr.c \
		  ft_putsigned.c ft_putstr.c ft_putunsigned.c \
		  ft_uitoa.c ft_isdigit.c errors.c ft_strncmp.c \

OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= fdf

all:		$(NAME)

objs/%.o: srcs/%.c
			@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJS)
			@cc $(OBJS)	$(CFLAGS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

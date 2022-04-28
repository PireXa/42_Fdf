# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 16:01:05 by fde-albe          #+#    #+#              #
#    Updated: 2022/04/28 10:02:07 by fde-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	controls.c calc_mesh.c connector.c designer.c \
		  		const_calc.c main.c valuescount.c ctrl_handlers.c \
		  		ctrl_handlers2.c calc_color.c initializers.c errors.c \

LIBFT_SRCS	=	get_next_line_utils_bonus.c get_next_line_bonus.c \
			 	ft_atoi.c ft_split.c ft_bzero.c ft_memset.c ft_calloc.c \
			 	ft_itoa.c ft_printf.c ft_putchar.c ft_puthex.c ft_puthexup.c \
			 	ft_putptr.c ft_putsigned.c ft_putstr.c ft_putunsigned.c \
				ft_uitoa.c ft_isdigit.c ft_strncmp.c ft_isspace.c \

OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

LIBFT_OBJS	= $(addprefix objs/,$(LIBFT_SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= fdf

all:		$(NAME)

objs/%.o: srcs/%.c
			@$(CC) $(CFLAGS) -Imlx -c $< -o $@

objs/%.o: libft_srcs/%.c
			@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJS) $(LIBFT_OBJS)
			@cc $(OBJS)	$(LIBFT_OBJS) $(CFLAGS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			@$(RM) $(OBJS) $(LIBFT_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

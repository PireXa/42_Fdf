# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 16:01:05 by fde-albe          #+#    #+#              #
#    Updated: 2022/04/13 16:01:08 by fde-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		fdf.c get_next_line.c get_next_line_utils.c \
			valuescount.c slope.c bargaksetra.c libft.a \
			designer.c calc_mesh.c \

CFLAGS =	-Wall -Wextra -Werror

RM	=		rm -f

NAME	=	fdf

all:		$(NAME)

$(NAME): 	$(SRCS)
			cc $(SRCS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

fclean:		
			$(RM) $(NAME)

re:			fclean all

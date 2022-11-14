SRCS		=	main.c \

OBJS		=	$(addprefix objs/,$(SRCS:.c=.o))

CFLAGS		= 	-g

RM		=	rm -f

NAME		=	minirt

all:		$(NAME)

objs/%.o: srcs/%.c
			@mkdir -p objs
			$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:		fclean all

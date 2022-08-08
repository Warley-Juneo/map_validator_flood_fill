LIBFT = ./libft/libft.a
SRC = map_validator.c
OBJS_SLG    = ${SRC:.c=.o}

CC            = gcc
CFLAGS        = -g3
RM            = rm -f
NAME          = map_validator

all:         ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I./libft

$(NAME):     $(LIBFT) $(OBJS_SLG)
			$(CC) $(CFLAGS) $(OBJS_SLG) $(LIBFT) -o $(NAME)

$(LIBFT):
			make -C ./libft

clean:
			make -C ./libft clean
			${RM} ${OBJS_SLG}

fclean:	 clean
			make -C ./libft fclean
			${RM} ${NAME}

re:		 fclean all

test:		all clean
			clear
			./${NAME}

val:		all clean
			clear
			valgrind -q --leak-check=full ./${NAME}

.PHONY:		all clean fclean re test val

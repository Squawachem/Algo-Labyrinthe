NAME =		labyrinthe.c

OUT =		exec.out

MAIN =		main.c

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

SOURCES =	

OBJS =		$(SOURCES:.c=.o)

all :		$(NAME)

$(NAME) :	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

exec :		$(NAME)
			$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(OUT)

norm :
			norminette $(SOURCES)

clean :
			-rm $(OBJS)

fclean :	clean
			-rm -f $(OUT) $(NAME)

re :		fclean all

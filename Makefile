NAME = labyrinthe

OUT = exec.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c gen_lab.c display_lab.c

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean :
	rm -f $(OUT) $(NAME)

re : fclean all

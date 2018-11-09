NAME = labyrinthe

OUT = exec.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c gen_lab.c display_lab.c menu.c

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean :
	rm -f $(OUT) $(NAME)

re : fclean all


coffee :
	@echo -n "\n\n                        (\n                         )     (\n                  ___...(-------)-....___\n              .-"
	@echo -n '""'
	@echo -n "       )    (          "
	@echo '""-.'
	@echo -n "        .-'"
	@echo -n '``'
	@echo  "'|-._             )         _.-|"
	@echo -n '       /  .--.|   `'
	@echo -n '""'
	@echo -n "---...........---"
	@echo -n '""'
	@echo '`   |'
	@echo "      /  /    |                             |"
	@echo "      |  |    |                             |"
	@echo "       \  \   |                             |"
	@echo -n "        "
	@echo '`\ `\ |                             |'
	@echo '          `\ `|                             |'
	@echo "          _/ /;                             ;"
	@echo "         (__/  \                           /"
	@echo -n "      _..---"
	@echo -n '""'
	@echo '` \                         /`""---.._'
	@echo "   .-'           \                       /          '-."
	@echo -n '  :               `-.__             __.-'
	@echo "'              :"
	@echo '  :                  ) ""---...---"" (                 :'
	@echo -n "   '._               "
	@echo -n '`"--...___...--"`              _.'
	@echo "'"
	@echo '     \""--..__                              __..--""/'
	@echo -n "      '._     "
	@echo -n '"""----.....______.....----"""     _.'
	@echo "'"
	@echo '         `""--..,,_____            _____,,..--""`'
	@echo -n '                       `"""----"""`'
	@echo "\t\tEnjoy drinking !\n"


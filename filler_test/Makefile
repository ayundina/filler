NAME = fillertest

RCS = main.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(RCS) -o $(NAME)

clean:

fclean: clean
	/bin/rm -r $(NAME)

make re: fclean all


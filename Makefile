# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ayundina <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/03 13:10:28 by ayundina      #+#    #+#                  #
#    Updated: 2019/06/05 15:19:15 by ayundina      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		ayundina.filler

FILES = 	main \
		ft_map \
		ft_piece \
		ft_fight \
		ft_check_n_print \
		ft_fill_gaps \
		ft_set \
		ft_reached \
		ft_path \
		ft_starting \
		ft_move_on_path \
		ft_move_random \
		ft_placement \
		ft_evaluate \
		ft_enemy_corner \
		ft_neighbours \
		ft_invalid_path_check

SRC_DIR =	./srcs

OBJ_DIR =	objs

SRCS =		$(patsubst %, $(SRC_DIR)/%.c,$(FILES))

OBJS =		$(patsubst %,$(OBJ_DIR)/%.o,$(FILES))

LIBFT_DIR =	./libft

LIBFT =		$(LIBFT_DIR)/libftprintf.a

INCL_DIR =	./includes

INCL =		$(INCL_DIR)/filler.h

CC =		gcc

FLAGS =		-g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -I $(INCL_DIR) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	@printf "\n1.$(OBJS)\n"
	@printf "\n2.$(SRCS)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL)
	$(CC) $(FLAGS) $< -c -o $@ -I $(INCL_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -rf $(OBJ_DIR)
#	printf "$(OBJS)"

fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)

re: fclean all

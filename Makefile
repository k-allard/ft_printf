# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 22:32:54 by kallard           #+#    #+#              #
#    Updated: 2020/07/15 18:48:54 by kallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = main.o

SRC = parser/ft_flags_parse.c \
		parser/ft_width_parse.c \
		parser/ft_precision_parse.c \
		parser/ft_length_parse.c \
		parser/ft_parser.c \
		processor/ft_int_type.c \
		processor/ft_char_type.c \
		processor/ft_e_type.c \
		processor/ft_f_inf_nan.c \
		processor/ft_n_type.c \
		processor/ft_percent_type.c \
		processor/ft_pointer_type.c \
		processor/ft_string_type.c \
		processor/ft_un_int_type.c \
		processor/ft_un_o_type.c \
		processor/ft_un_xx_type.c \
		processor/ft_processor.c \
       base/ft_printf.c

OBJS = $(SRC:.c=.o)


FLAGS = -g -Wall -Wextra -Werror

CC = gcc

HEADER = includes/*.h

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@ar r $(NAME) $(OBJS) libft/*.o
	@ranlib $(NAME)
	
test: $(TEST) $(NAME)
	@$(CC) -g -o project $(TEST) $(NAME) 
	@./project



clean:
	@rm -rf $(TEST)
	@rm -rf $(OBJS)
	@make -C libft clean
	@make -C pft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@make -C pft fclean
	@rm -rf ./project

re: fclean all

pft: fclean
	@make -C pft
	@pft/test X


%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

.PHONY:	all clean fclean re

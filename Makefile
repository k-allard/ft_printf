# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 22:32:54 by kallard           #+#    #+#              #
#    Updated: 2020/05/18 16:40:19 by kallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
TEST = main.o

SRC = parser/ft_flags_parse.c \
		parser/ft_width_parse.c \
		parser/ft_precision_parse.c \
		parser/ft_modifier_parse.c \
		parser/ft_parser.c \
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
       base/*.c

OBJS = $(SRC:.c=.o)


FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = includes/*.h

test: $(TEST) $(OBJS)
	@$(CC) -o project $(TEST) $(OBJS)
	@./project


all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@ar r $(NAME) $(OBJS)
	@ranlib $(NAME)


clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

.PHONY:	all clean fclean re

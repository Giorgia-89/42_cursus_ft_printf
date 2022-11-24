# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 15:09:05 by giorgia           #+#    #+#              #
#    Updated: 2022/11/24 10:46:33 by giorgia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf  ft_pointer ft_base ft_strcmp \
libft/ft_putnbr  \
libft/ft_putchar \
libft/ft_putstr  \
libft/ft_strdup  \
libft/ft_strlen  \

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o) 
fclean: clean
		$(RM) $(NAME)
re: fclean all
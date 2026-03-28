# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:48:30 by mcombeau          #+#    #+#              #
#    Updated: 2021/12/02 13:26:19 by mcombeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
SRC = ft_bzero \
	ft_calloc \
	ft_isdigit \
	ft_putendl_fd \
	ft_putstr_fd \
	ft_tolower \
	ft_toupper
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "Libft ready."

.c.o: $(SRCS)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@echo "Libft: removed .o object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Libft: removed libft.a file."

re: fclean all

.PHONY: all clean fclean re

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
SRC = ft_calloc.c \
	ft_isdigit.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_tolower.c \
	ft_toupper.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "Libft ready."

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Libft: removed .o object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Libft: removed libft.a file."

re: fclean all

.PHONY: all clean fclean re

#Program name
NAME	= fractol

# Compiler
CC		= cc
CFLAGS	= -Werror -Wextra -Wall

# Minilibx
UNAME		:= $(shell uname -s)
ifeq ($(UNAME),Darwin)
MLX_PATH	= minilibx-macos/
MLX_FLAGS	= -framework OpenGL -framework AppKit
else
MLX_PATH	= minilibx-linux/
MLX_FLAGS	= -lXext -lX11
endif
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./includes/\
					-I ./libft/\
					-I ./$(MLX_PATH)

# Sources
SRC_PATH	=	src/
	SRC			=	fractol.c \
					args.c \
					initialization.c \
					utils.c \
					events.c \
				render.c \
				color.c \
				parse_args.c \
				help_msg.c \
				fractal_sets/mandelbrot.c \
				fractal_sets/julia.c \
				fractal_sets/burning_ship.c \
				fractal_sets/tricorn.c \
				fractal_sets/mandelbox.c \
				color_schemes/color_interpolated.c \
				color_schemes/color_special.c \
				color_schemes/color_striped.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "Making MiniLibX..."
	@$(MAKE) -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@$(MAKE) -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) $(MLX_FLAGS) -lm
	@echo "Fractol ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean

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
SRC_PATH	= src/
CORE_SRC	= fractol.c \
			initialization.c \
			utils.c \
			parse_args.c \
			fractal_sets/mandelbrot.c \
			fractal_sets/julia.c \
			color_schemes/color_interpolated.c
MANDATORY_SRC = args.c \
				events.c \
				color.c \
				help_msg.c \
				render.c
BONUS_SRC	= args_bonus.c \
			events_bonus.c \
			color_bonus.c \
			help_msg_bonus.c \
			render_bonus.c \
			fractal_sets/burning_ship_bonus.c \
			fractal_sets/tricorn_bonus.c \
			fractal_sets/mandelbox_bonus.c \
			color_schemes/color_special_bonus.c \
			color_schemes/color_striped_bonus.c

# Objects
OBJ_PATH		= obj/
MANDATORY_OBJ	= $(CORE_SRC:.c=.o) $(MANDATORY_SRC:.c=.o)
BONUS_OBJ		= $(CORE_SRC:.c=.o) $(BONUS_SRC:.c=.o)
MANDATORY_OBJS	= $(addprefix $(OBJ_PATH), $(MANDATORY_OBJ))
BONUS_OBJS		= $(addprefix $(OBJ_PATH), $(BONUS_OBJ))
MANDATORY_MARK	= $(OBJ_PATH).mandatory_build
BONUS_MARK		= $(OBJ_PATH).bonus_build

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@echo "Making MiniLibX..."
	@$(MAKE) -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@$(MAKE) -sC $(LIBFT_PATH)

$(NAME): $(MANDATORY_MARK)

$(MANDATORY_MARK): $(MANDATORY_OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS) $(MLX) $(LIBFT) $(INC) $(MLX_FLAGS) -lm
	@echo "Fractol ready."
	@rm -f $(BONUS_MARK)
	@touch $@

bonus: $(MLX) $(LIBFT) $(BONUS_MARK)

$(BONUS_MARK): $(BONUS_OBJS)
	@echo "Compiling fractol bonus..."
	@$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(MLX) $(LIBFT) $(INC) $(MLX_FLAGS) -lm
	@echo "Fractol bonus ready."
	@rm -f $(MANDATORY_MARK)
	@touch $@

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

.PHONY: all bonus re clean fclean

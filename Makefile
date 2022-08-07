CC = clang
CFLAGS =  -Iheaders -Imlx_linux -O3 -Wall -Wextra -Werror -g -c
LFLAGS =  -L. -lft -lm

MLX_FLAGS = -L. -lmlx_linux -lXext -lX11 -lz  
NAME = fractol

OBJ_DIR = obj
OBJ_DIR_CHILDS = $(OBJ_DIR)/fractals/mandelbrot
HEADERS = headers/fractol.h

TARGETS = 	main.c \
			mlx_core/put_pixel_to_img.c \
			mlx_core/draw.c \
			mlx_core/get_pixel_addr.c \
			mlx_core/hooks.c \
			mandelbrot/mandelbrot.c \
			mandelbrot/mandelbrot_viewport.c \
			mandelbrot/mandelbrot_colors.c \
			julia/julia_viewport.c \
			julia/julia.c \
			utils/zoom.c \
			utils/check_fractal_name.c \
			utils/get_coordinate.c \
			utils/ctx_default.c \
			utils/move.c \
			utils/print_help.c \
			utils/exit.c \
			utils/theme.c \
			utils/assign_fractal.c \
			inicialization/ctx_init.c \
			inicialization/view_init.c \
			inicialization/window_init.c \
			inicialization/img_init.c \
			inicialization/colors_init.c \
			inicialization/init_mandelbrot.c

SRC = $(addprefix ./src/,$(TARGETS)) 
OBJ = $(addprefix ./$(OBJ_DIR)/,$(TARGETS:.c=.o)) 
MLX = libmlx_linux.a
LIBFT = libft.a

all: re 

re: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(MLX) $(LIBFT) 
	$(CC) $(OBJ) $(LFLAGS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS)  $< -o $@

$(MLX):
	make -C libmlx_linux
	cp libmlx_linux/libmlx_Linux.a $(MLX)

$(LIBFT):
	make -C libft
	cp libft/libft.a $(LIBFT) 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/inicialization
	mkdir -p $(OBJ_DIR)/mandelbrot
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/mlx_core
	mkdir -p $(OBJ_DIR)/julia


dclean: fclean
	make -C libmlx_linux clean
	make -C libft fclean

clean: 
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MLX)


.PHONY: dclean clean fclean all re
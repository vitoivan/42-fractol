/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:17 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 11:24:03 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define WIN_TITLE "Fract-ol"
# define MAX_ITERATIONS 100

enum			e_keycodes
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	Q = 113,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
	NUM_1 = 49,
	NUM_2 = 50,
	NUM_3 = 51,
	NUM_4 = 52,
	NUM_5 = 53,
};

enum			e_events
{
	DESTROY = 17,
	BUTTONPRESS_MASK = (1L << 2),
};

typedef struct s_complex
{
	long double	real;
	long double	imaginary;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_view
{
	long double	zoom;
	t_complex	coordinate;
	long double	offset_x;
	long double	offset_y;
	long double	pixel_size_x;
	long double	pixel_size_y;
	int			colors[MAX_ITERATIONS + 1];
	t_complex	c;

}				t_view;

typedef struct s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct s_ctx
{
	void		*mlx;
	void		*window;
	t_img		*img;
	t_view		*view;
	int			theme;
	void		(*fn)(struct s_ctx *ctx, int x, int y);
}				t_ctx;

// Inits
t_ctx			*ctx_init(t_ctx *ctx);
t_view			*view_init(t_ctx *ctx);
t_img			*img_init(t_ctx *ctx);
void			*window_init(t_ctx *ctx);
void			colors_init(t_ctx *ctx);
void			init_mandelbrot(t_ctx *ctx, int argc, char **argv);

// Utils
int				exit_program(t_ctx *ctx);
t_complex		get_coordinate(int x, int y, t_ctx *ctx);
int				get_colors(int i, t_ctx *ctx);
void			zoom(t_ctx *ctx, int mouse_x, int mouse_y, void (*fn)(t_ctx *,
						int, int), int z);
void			print_help(void);
void			assign_fractal(t_ctx *ctx, int argc, char **argv);
void			check_fractal_name(char *name);
int				check_valid_theme(char *str);
int				move(t_ctx *ctx, long double x, long double y,
					void (*fn)(t_ctx *, int, int));

// Mlx
void			draw(t_ctx *ctx, void (*fn)(t_ctx *, int, int));
int				register_hooks(t_ctx *ctx);
char			*get_pixel_addr(t_img *img, int x, int y);
void			put_pixel_to_img(t_img *img, int x, int y, int color);

// Viewports
void			set_mandelbrot_viewport(t_view *v);
void			set_julia_viewport(t_view *v);

// fractals
void			mandelbrot(t_ctx *ctx, int x, int y);
void			julia(t_ctx *ctx, int x, int y);

#endif

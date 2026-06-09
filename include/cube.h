/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 01:36:13 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/23 01:36:13 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define HEIGHT 800
# define WIDTH 800
# define MAX_MAP_SIZE 1000
# define MOVE_SPEED 0.005
# define ROT_SPEED 0.005

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100

// Parsing
typedef struct s_check
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_check;

typedef struct s_arg
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**map;
	int		f_color[3];
	int		c_color[3];
	int		f_defined;
	int		c_defined;
	int		map_size;
}	t_arg;

//RENDER

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_tex
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
}	t_tex;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_key;

typedef struct s_game
{
	t_player	player;
	t_mlx		mlx;
	t_img		img;
	t_tex		tex;
	t_map		map;
	t_ray		ray;
	t_key		key;
	int			floor_color;
	int			ceiling_color;
}	t_game;

//check cub file
int		pre_parse(char *file);
void	init_check(t_check *c);
int		is_id_valid(char *line, t_check *c);
char	*skip_spaces(char *line);
int		is_not_empty_line(char *line);
int		check_id(t_check *c);
int		check_map_line(char *line);

// parsing
int		parsing(char *file, t_arg *data);
int		is_texture(char *line);
int		is_color(char *line);
int		is_map_line(char *line);
int		parse_texture(char *line, t_arg *data);
int		parse_color(char *line, t_arg *data);
int		add_to_map(char *line, t_arg *data);
int		validate_map(t_arg *data);
int		is_only_spaces(char *line);
void	remove_nl(char *line);
int		all_set(t_arg *data);

// init
t_arg	*init_arg(void);
void	init_game(t_game *game, t_arg *arg);
void	init_all(t_game *game, t_arg *arg);
void	set_direction(t_game *game, char c);
void	init_colors(t_game *game, t_arg *arg);
void	set_direction(t_game *game, char c);

//hook
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		key_handler(t_game *game);
void	rotate_right(t_player *p);
void	rotate_left(t_player *p);
void	move_w(t_player *player, t_map *map);
void	move_a(t_player *player, t_map *map);
void	move_s(t_player *player, t_map *map);
void	move_d(t_player *player, t_map *map);

//free & error msg
void	clean_exit_game(t_game *game, t_arg *data);
void	err_msg(char *msg);
void	free_arg(t_arg *data);
void	err_cub_format(void);
void	free_close(char *line, int fd);
void	free_game(t_game *game);
void	free_tab(char **tab);
int		handle_close(t_game *game);

//debug
void	print_data(t_arg *data);

//render
int		game_loop(t_game *game);
int		render_frame(t_game *game);
int		raycast(t_game *g);
void	draw_column(t_game *g, int x);
void	calc_wall(t_game *g);
void	put_pixel(t_img *img, int x, int y, int color);

#endif
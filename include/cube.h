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

# define HEIGHT 800
# define WIDTH 800
# define MAX_MAP_SIZE 1000

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define WHEELUP 4
# define WHEELDOWN 5

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

typedef struct s_game
{
	t_player	player;
	t_mlx		mlx;
	t_img		img;
	t_tex		tex;
	t_map		map;
	//t_ray		ray;
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

// init
t_arg	*init_arg(void);
void	init_game(t_game *game, t_arg *arg);
void	init_all(t_game *game, t_arg *arg);

//hook
int	key_handler(int keycode, t_game *game);

//free & error msg
void	clean_exit_game(t_game *game);
void	err_msg(char *msg);
void	free_arg(t_arg *data);
void	err_cub_format(void);
void	free_close(char *line, int fd);
void	free_game(t_game *game);
void	free_tab(char **tab);
int		handle_close(t_game *game);

//debug
void	print_data(t_arg *data);

#endif
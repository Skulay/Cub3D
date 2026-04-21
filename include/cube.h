#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 800
# define WIDTH 800

typedef struct s_arg
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char **map;
	int f_color[3];
	int c_color[3];
	int f_defined;
	int c_defined;

} t_arg;

typedef struct s_cube
{
	void *mlx;
	void *image;
	void *window;
	void *buffer;
} t_cube;

// parsing
int	parsing(char *file, t_arg *data);
int	is_texture(char *line);
int	is_color(char *line);
int	parse_texture(char *line, t_arg *data);
int	parse_color(char *line, t_arg *data);

// init
t_arg	*init_arg(void);

// window

void	cube_init(t_cube *cube);

#endif
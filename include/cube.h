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
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char **map;
	int f_color[3];
	int c_color[3];
	int f_defined;
	int c_defined;
	int map_size;
}	t_arg;

typedef struct s_cube
{
	void *mlx;
	void *image;
	void *window;
	void *buffer;
}	t_cube;

//check cub file
int pre_parse(char *file);
void init_check(t_check *c);

// parsing
int	parsing(char *file, t_arg *data);
int	is_texture(char *line);
int	is_color(char *line);
int is_map_line(char *line);
int	parse_texture(char *line, t_arg *data);
int	parse_color(char *line, t_arg *data);
int add_to_map(char *line, t_arg *data);
int	validate_map(t_arg *data);

// init
t_arg	*init_arg(void);

// window
void	cube_init(t_cube *cube);

//free & error msg
void	err_cub_format(void);
void	free_close(char *line, int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/12/10 16:02:21 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> // printf to remove
# include <math.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define MOVE_SPEED 0.08
# define ROTATE_SPEED 0.05

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define MINIMAP_SCALE 8

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

# define PLAYER_COLOR 0x003A8DFF

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	char	*path;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		floor_rgb[3];
	int		ceil_rgb[3];
	int		x;
	int		y;
	float	step;
	float	pos;
}	t_image;

typedef struct wall
{
	short	side;
	short	start;
	short	end;
	short	height;
}	t_wall;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	plane_offset;
	double	length;
	short	map_x;
	short	map_y;
	short	step_x;
	short	step_y;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	short		map_width;
	short		map_height;
	t_player	*player;
	t_ray		*ray;
	t_wall		*wall;
	t_image		*image;
	t_image		*minimap;
	t_image		texture[4];
}	t_data;

void	parse_map(t_data *data, char *path);
void	start_game(t_data *data);
void	cast_rays(t_data *data);
void	draw_wall(t_data *data, short x);
void	draw_background(t_image *image);
void	draw_minimap(t_data *data);
void	init_wall(t_data *data);
void	put_pixel(t_image *image, int x, int y, int color);
void	get_distance_fog(t_image *image, int x, int y, bool is_ceil);
void	put_square(t_data *data, int x, int y, int color);
void	map_texture(t_data *data, t_image *texture);
int		handle_mouse_events(int x, int y, t_data *data);
int		handle_key_events(int keycode, t_data *data);
int		close_game(t_data *data);
void	free_map(char **map);
void	print_error(char *msg);
void	fill_1s(char **map);
int		process_map(t_data *data, char *map);
bool	check_extension(char *file, char *ext);
int		len_to_space(char *s);
char	*fix_spaces(char *str);
bool	open_vertical(char **map);
bool	open_horizontal(char **map);
int		count_cols(char **arr);
int		count_rows(char **arr);
bool	is_valid_char(char c);
bool	is_valid(char **map, t_image txts[4]);
int		ft_strheight(char **str);
char	**copy_array(char **arr);
int		count_rows_col(char **arr, int col);
char	**copy_array(char **arr);
void	free_data(t_data *data);

#endif

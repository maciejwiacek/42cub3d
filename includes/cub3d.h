/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:10:30 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/17 13:23:28 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../my_lib/includes/get_next_line.h"
# include "../my_lib/includes/libft.h"
# include "../my_lib/includes/printf.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_txt
{
	t_img	*NO;
	t_img	*SO;
	t_img	*WE;
	t_img	*EA;
	int		F;
	int		C;
}	t_txt;

typedef struct s_game
{
	void	*mlx;
	char	**map;
	t_txt	*txt;
}	t_game;

// INIT
void	init_game(t_game *game, char *av);
void	parse_map(t_game *game, char *av);
t_txt	*parse_textures(t_game *game, char **map);

// UTILS
bool	check_extension(char *file, char *ext);
void	print_error(char *msg);
t_dict	to_dict(char *str);

#endif
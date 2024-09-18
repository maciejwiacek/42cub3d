/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:46:50 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/18 14:49:15 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*xpm_to_img(t_game *game, char *path)
{
	t_img	*img;
	int		fd;

	img = malloc(sizeof(t_img));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Wrong texture path\n");
	close (fd);
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	return (img);
}

static int	rgb_to_hex(char *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(color);
	color = ft_strchr(color, ',') + 1;
	g = ft_atoi(color);
	color = ft_strchr(color, ',') + 1;
	b = ft_atoi(color);
	return ((r << 16) | (g << 8) | b);
}

t_txt	*parse_textures(t_game *game, char **map)
{
	int		i;
	t_txt	*txt;
	char	*tmp;

	txt = malloc(sizeof(t_txt));
	i = 0;
	while (i < 6)
	{
		tmp = fix_spaces(map[i]);
		if (!ft_strncmp(tmp, "NO", len_to_space(tmp)))
			txt->NO = xpm_to_img(game, tmp + 3);
		else if (!ft_strncmp(tmp, "SO", len_to_space(tmp)))
			txt->SO = xpm_to_img(game, tmp + 3);
		else if (!ft_strncmp(tmp, "WE", len_to_space(tmp)))
			txt->WE = xpm_to_img(game, tmp + 3);
		else if (!ft_strncmp(tmp, "EA", len_to_space(tmp)))
			txt->EA = xpm_to_img(game, tmp + 3);
		else if (!ft_strncmp(tmp, "F", len_to_space(tmp)))
			txt->F = rgb_to_hex(tmp + 2);
		else if (!ft_strncmp(tmp, "C", len_to_space(tmp)))
			txt->C = rgb_to_hex(tmp + 2);
		free(tmp);
		++i;
	}
	if (!(txt->NO && txt->SO && txt->WE && txt->EA && txt->F && txt->C))
	{
		free_txt(game, txt);
		return (NULL);
	}
	return (txt);
}

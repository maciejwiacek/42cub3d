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
	t_dict	txt_dict[6];

	i = 0;
	while (map[i][0] && ft_isalpha(map[i][0]))
	{
		txt_dict[i] = to_dict(map[i]);
		++i;
	}
	txt = malloc(sizeof(t_txt));
	i = 0;
	while (map[i + 1][0] && map[i + 1][0] != '1')
	{
		if (!ft_strncmp(txt_dict[i].key, "NO", ft_strlen(txt_dict[i].key)))
			txt->NO = xpm_to_img(game, txt_dict[i].value);
		else if (!ft_strncmp(txt_dict[i].key, "SO", ft_strlen(txt_dict[i].key)))
			txt->SO = xpm_to_img(game, txt_dict[i].value);
		else if (!ft_strncmp(txt_dict[i].key, "WE", ft_strlen(txt_dict[i].key)))
			txt->WE = xpm_to_img(game, txt_dict[i].value);
		else if (!ft_strncmp(txt_dict[i].key, "EA", ft_strlen(txt_dict[i].key)))
			txt->EA = xpm_to_img(game, txt_dict[i].value);
		else if (!ft_strncmp(txt_dict[i].key, "F", ft_strlen(txt_dict[i].key)))
			txt->F = rgb_to_hex(txt_dict[i].value);
		else if (!ft_strncmp(txt_dict[i].key, "C", ft_strlen(txt_dict[i].key)))
			txt->C = rgb_to_hex(txt_dict[i].value);
		++i;
	}
	if (!(txt->NO && txt->SO && txt->WE && txt->EA && txt->F && txt->C))
		print_error("Wrong textures\n");
	return (txt);
}
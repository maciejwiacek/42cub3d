#include "../../includes/cub3d.h"

t_img	*xpm_to_img(t_game *game, char *path)
{
	t_img	*img;
	int		fd;

	img = malloc(sizeof(t_img));
	fd = open(path, O_RDONLY);
	printf("%s\n", path);
	if (fd < 0)
		print_error("Wrong texture path\n");
	close (fd);
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	return (img);
}

t_txt	*parse_textures(t_game *game, char **map)
{
	int		i;
	t_txt	*txt;
	t_dict	txt_dict[6];

	i = -1;
	while (++i < 6)
		txt_dict[i] = to_dict(map[i]);
	txt = malloc(sizeof(t_txt));
	i = -1;
	while (++i < 4)
	{
		if (!ft_strncmp(txt_dict[i].key, "NO", ft_strlen(txt_dict[i].key)))
			txt->NO = xpm_to_img(game, txt_dict[i].value);
		if (!ft_strncmp(txt_dict[i].key, "SO", ft_strlen(txt_dict[i].key)))
			txt->SO = xpm_to_img(game, txt_dict[i].value);
		if (!ft_strncmp(txt_dict[i].key, "WE", ft_strlen(txt_dict[i].key)))
			txt->WE = xpm_to_img(game, txt_dict[i].value);
		if (!ft_strncmp(txt_dict[i].key, "EA", ft_strlen(txt_dict[i].key)))
			txt->EA = xpm_to_img(game, txt_dict[i].value);
	}
	return (txt);
}
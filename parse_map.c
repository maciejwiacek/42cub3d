/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:08:55 by msmajdor          #+#    #+#             */
/*   Updated: 2024/12/10 16:01:58 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *player, char direction)
{
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->dir = direction;
	if (direction == 'N')
		player->dir_y = -1;
	else if (direction == 'S')
		player->dir_y = 1;
	else if (direction == 'W')
		player->dir_x = -1;
	else if (direction == 'E')
		player->dir_x = 1;
	if (direction == 'N')
		player->plane_x = 0.75;
	else if (direction == 'S')
		player->plane_x = -0.75;
	else if (direction == 'W')
		player->plane_y = 0.75;
	else if (direction == 'E')
		player->plane_y = -0.75;
}

static void	find_player(t_data *data)
{
	short	x;
	short	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N'
			|| data->map[y][x] == 'S'
			|| data->map[y][x] == 'W'
			|| data->map[y][x] == 'E')
			{
				data->player->pos_x = x + 0.5;
				data->player->pos_y = y + 0.5;
				init_player(data->player, data->map[y][x]);
			}
			x++;
		}
		y++;
	}
	data->map_width = x;
	data->map_height = y;
}

static char	*read_map(char *path)
{
	char	*line;
	char	*map;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Wrong map path\n");
	line = get_next_line(fd);
	if (!line)
		print_error("Map file is empty\n");
	map = ft_strdup("");
	if (!map)
		return (NULL);
	while (line)
	{
		map = ft_strjoin_free(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (free(line), map);
}

static void	init_data(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	data->ray = malloc(sizeof(t_ray));
	data->wall = malloc(sizeof(t_wall));
	data->minimap = malloc(sizeof(t_image));
	data->image = malloc(sizeof(t_image));
	data->texture[0].path = NULL;
	data->texture[1].path = NULL;
	data->texture[2].path = NULL;
	data->texture[3].path = NULL;
	data->image->floor_rgb[0] = -1;
	data->image->ceil_rgb[0] = -1;
}

void	parse_map(t_data *data, char *path)
{
	char	*map;

	if (!check_extension(path, ".cub"))
		print_error("Wrong map extension\n");
	map = read_map(path);
	if (!map)
		print_error("Reading map file failed\n");
	init_data(data);
	if (process_map(data, map) != 0)
	{
		free_data(data);
		free(map);
		print_error("Wrong textures\n");
	}
	free(map);
	if (!is_valid(data->map, data->texture))
	{
		free_data(data);
		free_map(data->map);
		print_error("Map is invalid\n");
	}
	fill_1s(data->map);
	find_player(data);
	data->map_width = ft_strlen(data->map[0]);
	data->map_height = ft_strheight(data->map);
}

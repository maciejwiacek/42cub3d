/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:34:04 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/18 15:05:42 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		print_error("Map file is empty!\n");
	map = ft_strdup("");
	if (!map)
		return (NULL);
	while (line)
	{
		if (line[0] != '\n')
		{
			map = ft_strjoin_free(map, line);
			if (!map)
				return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (free(line), map);
}

static void	process_map(t_game *game, char *map)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_split(map, '\n');
	game->txt = parse_textures(game, res);
	if (!game->txt)
	{
		free_arr(res);
		return ;
	}
	while (i < 6)
		free(res[i++]);
	game->map = res += 6;
}

void	parse_map(t_game *game, char *path)
{
	char	*map;
	int		i;

	i = 0;
	if (!check_extension(path, ".cub"))
		print_error("Wrong map extension\n");
	map = read_map(path);
	if (!map)
		print_error("Reading map file failed\n");
	process_map(game, map);
	free(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:34:04 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/17 13:28:32 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*read_map(int fd)
{
	char	*line;
	char	*map;

	line = get_next_line(fd);
	if (!line)
		print_error("Map file is empty!\n");
	map = NULL;
	map = ft_strdup("");
	while (line)
	{
		if (line[0] != '\n')
			map = ft_strjoin_free(map, line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

static char	**process_map(t_game *game, char *map)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_split(map, '\n');
	game->txt = parse_textures(game, res);
	while (i < 6)
	{
		free(res[i]);
		i++;
	}
	return (&res[i]);
}

void	parse_map(t_game *game, char *av)
{
	int		map_fd;
	char	*map;
	int		i;

	i = 0;
	if (!check_extension(av, ".cub"))
		print_error("Wrong map extension\n");
	map_fd = open(av, O_RDONLY);
	if (map_fd < 0)
		print_error("Wrong map\n");
	map = read_map(map_fd);
	game->map = process_map(game, map);
	while (game->map[0][i] == ' ')
		i++;
	if (game->map[0][i] != '1')
		print_error("Map format is wrong\n");
	free(map);
	close(map_fd);
}

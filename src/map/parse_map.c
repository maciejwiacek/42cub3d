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
		map = ft_strjoin_free(map, line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

void	parse_map(t_game *game, char *av)
{
	int		map_fd;
	char	*map;
	// char	**map_split;

	(void)game;
	if (!check_extension(av, ".cub"))
		print_error("Wrong map extension\n");
	map_fd = open(av, O_RDONLY);
	if (map_fd < 0)
		print_error("Wrong map\n");
	map = read_map(map_fd);
	printf("%s\n", map);
	// game->map = map;
	close(map_fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:34:04 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/16 14:36:03 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_map(t_game *game, char *av)
{
	int		map_fd;
	char	**map;

	map_fd = open(av, O_RDONLY);
	game->map = map;
	close(map_fd);
}
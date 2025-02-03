/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:30:08 by mwiacek           #+#    #+#             */
/*   Updated: 2024/12/10 15:26:54 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	has_correct_symbols(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (!map[i][j])
			return (false);
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	has_one_player(char **map)
{
	int		i;
	int		j;
	bool	is_player;

	i = 0;
	is_player = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'S' || map[i][j] == 'W')
			{
				if (is_player)
					return (false);
				is_player = true;
			}
			j++;
		}
		i++;
	}
	return (is_player);
}

static bool	has_borders(char **map)
{
	if (open_horizontal(map))
		return (false);
	if (open_vertical(map))
		return (false);
	return (true);
}

static bool	has_valid_textures(t_image txts[4])
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(txts[i].path, O_RDONLY);
		if (fd < 0)
			return (false);
		close(fd);
		i++;
	}
	return (true);
}

bool	is_valid(char **map, t_image txts[4])
{
	if (!has_correct_symbols(map))
		return (false);
	if (!has_one_player(map))
		return (false);
	if (!has_borders(map))
		return (false);
	if (!has_valid_textures(txts))
		return (false);
	return (true);
}

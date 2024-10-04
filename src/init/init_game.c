/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:32:40 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/30 21:09:01 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_game(t_game *game, char *map_path)
{
	game->mlx = mlx_init();
	parse_map(game, map_path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:10:05 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/16 14:32:20 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		print_error("Wrong amount of arguments\n");
	init_game(&game, av[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:10:05 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/18 14:56:32 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		print_error("Wrong amount of arguments\n");
	init_game(&game, av[1]);
	printf("----- TEXTURES -----\n");
	printf("EA: %s\n", game.txt->EA->addr);
	printf("WE: %s\n", game.txt->WE->addr);
	printf("NO: %s\n", game.txt->NO->addr);
	printf("SO: %s\n", game.txt->SO->addr);
	printf("----- COLORS -----\n");
	printf("C: %d\n", game.txt->C);
	printf("F: %d\n", game.txt->F);
	printf("-----   MAP   -----\n");
	for (int i = 0; game.map[i]; i++)
		printf("%s\n", game.map[i]);
}

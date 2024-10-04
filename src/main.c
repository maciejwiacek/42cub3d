/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:10:05 by mwiacek           #+#    #+#             */
/*   Updated: 2024/10/03 13:23:33 by mwiacek          ###   ########.fr       */
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
	printf("EA: %d\n", game.txt->EA->width);
	printf("WE: %d\n", game.txt->WE->width);
	printf("NO: %d\n", game.txt->NO->width);
	printf("SO: %d\n", game.txt->SO->width);
	printf("----- COLORS -----\n");
	printf("C: %d\n", game.txt->C);
	printf("F: %d\n", game.txt->F);
	printf("-----   MAP   -----\n");
	for (int i = 0; game.map[i]; i++)
		printf("%s\n", game.map[i]);
}

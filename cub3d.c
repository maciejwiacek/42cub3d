/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:13 by msmajdor          #+#    #+#             */
/*   Updated: 2024/12/09 19:22:38 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		print_error("Wrong amount of arguments\n");
	parse_map(&data, av[1]);
	start_game(&data);
	return (0);
}

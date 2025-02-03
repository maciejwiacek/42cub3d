/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_1s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:18:08 by mwiacek           #+#    #+#             */
/*   Updated: 2024/12/10 13:46:57 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_1s(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[i])
	{
		j = 0;
		k = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ' && map[i][j])
			j++;
		while (map[i][k] == ' ' && k > j)
			k--;
		while (map[i][j] && j < k)
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

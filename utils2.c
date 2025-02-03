/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:49:14 by mwiacek           #+#    #+#             */
/*   Updated: 2024/12/10 15:38:29 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**allocate_arr(char **arr, int len)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		res[i] = ft_strdup(arr[i]);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	count_rows_col(char **arr, int col)
{
	int	row;

	row = 0;
	while (arr[row])
	{
		if (col < 0 || col >= (int)ft_strlen(arr[row]))
			break ;
		if (!is_valid_char(arr[row][col]))
			break ;
		row++;
	}
	return (row);
}

char	**copy_array(char **arr)
{
	int		len;
	char	**res;

	if (!arr)
		return (NULL);
	len = 0;
	while (arr[len])
		len++;
	res = allocate_arr(arr, len);
	return (res);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->texture[i].path && i < 4)
		free(data->texture[i++].path);
	free(data->player);
	free(data->ray);
	free(data->wall);
	free(data->minimap);
	free(data->image);
}

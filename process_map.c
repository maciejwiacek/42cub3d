/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:01:17 by mwiacek           #+#    #+#             */
/*   Updated: 2024/12/10 15:36:45 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_hex(int data[3], char *s)
{
	char	*tmp;
	int		i;

	tmp = s;
	i = 0;
	while (i < 3)
	{
		data[i] = ft_atoi(tmp);
		if (data[i] > 255 || data[i] < 0)
			return (1);
		tmp = ft_strchr(s, ',') + 1;
		i++;
	}
	return (0);
}

static bool	validate_texture(t_image *txt, t_image *color, char *s)
{
	if (!ft_strncmp(s, "NO", len_to_space(s)) && !txt[0].path)
		return (true);
	else if (!ft_strncmp(s, "EA", len_to_space(s)) && !txt[1].path)
		return (true);
	else if (!ft_strncmp(s, "SO", len_to_space(s)) && !txt[2].path)
		return (true);
	else if (!ft_strncmp(s, "WE", len_to_space(s)) && !txt[3].path)
		return (true);
	else if (!ft_strncmp(s, "F", len_to_space(s)) && color->floor_rgb[0] < 0)
		return (true);
	else if (!ft_strncmp(s, "C", len_to_space(s)) && color->ceil_rgb[0] < 0)
		return (true);
	return (false);
}

static void	parse_texture(t_image *txt, t_image *img, char *s)
{
	if (!ft_strncmp(s, "NO", len_to_space(s)))
		txt[0].path = ft_strdup(s + 3);
	else if (!ft_strncmp(s, "EA", len_to_space(s)))
		txt[1].path = ft_strdup(s + 3);
	else if (!ft_strncmp(s, "SO", len_to_space(s)))
		txt[2].path = ft_strdup(s + 3);
	else if (!ft_strncmp(s, "WE", len_to_space(s)))
		txt[3].path = ft_strdup(s + 3);
	else if (!ft_strncmp(s, "F", len_to_space(s)))
		rgb_to_hex(img->floor_rgb, s + 2);
	else if (!ft_strncmp(s, "C", len_to_space(s)))
		rgb_to_hex(img->ceil_rgb, s + 2);
}

static int	parse_textures(t_data *data, char **map, int *i)
{
	char	*tmp;
	int		txt_count;

	txt_count = 0;
	while (txt_count < 6)
	{
		tmp = fix_spaces(map[*i]);
		if (tmp[0] != '\n' && validate_texture(data->texture, data->image, tmp))
		{
			parse_texture(data->texture, data->image, tmp);
			txt_count++;
		}
		else if (tmp[0] != '\n')
			return (free(tmp), 1);
		free(tmp);
		++(*i);
	}
	return (0);
}

int	process_map(t_data *data, char *map)
{
	char	**res;
	int		i;
	int		txts;

	txts = 0;
	i = 0;
	res = ft_split(map, '\n');
	txts = parse_textures(data, res, &i);
	if (txts != 0)
	{
		free_map(res);
		return (1);
	}
	data->map = copy_array(res + i);
	free_map(res);
	return (0);
}

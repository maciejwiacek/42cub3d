/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:23:00 by mwiacek           #+#    #+#             */
/*   Updated: 2024/12/10 13:47:43 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_extension(char *file, char *ext)
{
	int	len;
	int	name_len;

	len = ft_strlen(ext);
	name_len = ft_strlen(file);
	if (!ft_strncmp(file + name_len - len, ext, len))
		return (true);
	return (false);
}

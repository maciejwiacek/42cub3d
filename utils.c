/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:23:32 by mwiacek           #+#    #+#             */
/*   Updated: 2024/12/10 13:48:08 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strheight(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	len_to_space(char *s)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != ' ')
		count++;
	return (count);
}

static int	calculate_len(char *str)
{
	int	count;
	int	i;
	int	word_count;

	count = 0;
	word_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			word_count++;
		while (str[i] && str[i] != ' ')
		{
			i++;
			count++;
		}
	}
	return (count + word_count - 1);
}

char	*fix_spaces(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(calculate_len(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
			res[j++] = str[i++];
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
			res[j++] = ' ';
	}
	res[j] = '\0';
	return (res);
}

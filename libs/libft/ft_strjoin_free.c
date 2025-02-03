/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:46:49 by mwiacek           #+#    #+#             */
/*   Updated: 2024/12/10 13:46:38 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *src, char *dst)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

static void	ft_strcat(char *s1, char *s2)
{
	while (*s1)
		s1++;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	ft_strcpy(s1, result);
	ft_strcat(result, s2);
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (result);
}

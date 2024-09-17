#include "../../includes/cub3d.h"

static int	ft_strlen_trim(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

t_dict	to_dict(char *str)
{
	char	*key;
	char	*value;
	int		i;
	t_dict	dict;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		print_error("Wrong texture format\n");
	key = malloc(ft_strlen_trim(&str[i]) + 1);
	ft_strlcpy(key, &str[i], ft_strlen_trim(&str[i]) + 1);
	i += ft_strlen_trim(&str[i]);
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		print_error("Wrong texture format\n");
	value = malloc(ft_strlen_trim(&str[i]) + 1);
	ft_strlcpy(value, &str[i], ft_strlen_trim(&str[i]) + 1);
	dict.key = key;
	dict.value = value;
	return (dict);
}
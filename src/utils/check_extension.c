#include "../../includes/cub3d.h"

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
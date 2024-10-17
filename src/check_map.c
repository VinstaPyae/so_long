#include "so_long.h"

int	is_rectangular(t_mpp *mp_info)
{
	int	i;

	i = 0;
	mp_info->width = ft_strlen(mp_info->map_file[0]);
	while (mp_info->map_file[i])
	{
		if (ft_strlen(mp_info->map_file[i]) != mp_info->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_invalid_elements(t_mpp *mp_info, int i, int j)
{
	while (mp_info->map_file[++i])
	{
		while (mp_info->map_file[i][++j])
		{
			if (mp_info->map_file[i][j] == '1')
				mp_info->walls++;
			else if (mp_info->map_file[i][j] == '0')
				mp_info->path++;
			else if (mp_info->map_file[i][j] == 'C')
				mp_info->collectibles++;
			else if (mp_info->map_file[i][j] == 'P')
				mp_info->player++;
			else if (mp_info->map_file[i][j] == 'E')
				mp_info->exit++;
			else
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_elements(t_mpp *mp_info)
{
	if (!check_invalid_elements(mp_info, -1, -1))
		ft_error_map(mp_info);
	if (mp_info->player != 1 || mp_info->exit != 1 || mp_info->collectibles < 1)
		ft_error_map(mp_info);
	return (1);
}

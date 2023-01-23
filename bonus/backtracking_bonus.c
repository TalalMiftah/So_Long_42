#include "../so_long.h"

int	count_c(char **c)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 0;
	r = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == 'C')
				r++;
			j++;
		}
		i++;
	}
	return (r);
}

int	position1(char **map, int i, int j)
{
	int	c;

	c = count_c(map);
	if (c == 0)
		return (1);
	if (map[i][j] == 'E')
		return (0);
	if (map[i][j] == '1')
		return (0);
	map[i][j] = '1';
	if (position1(map, i, j + 1))
		return (1);
	if (position1(map, i, j - 1))
		return (1);
	if (position1(map, i + 1, j))
		return (1);
	if (position1(map, i - 1, j))
		return (1);
	return (0);
}

int	position(char **map, int i, int j)
{
	if (map[i][j] == 'E')
		return (1);
	if (map[i][j] == '1')
		return (0);
	map[i][j] = '1';
	if (position(map, i, j + 1))
		return (1);
	if (position(map, i, j - 1))
		return (1);
	if (position(map, i + 1, j))
		return (1);
	if (position(map, i - 1, j))
		return (1);
	return (0);
}

void	backtracking_col(t_list *so_long)
{
	char	**arr1;
	int		i;

	i = 0;
	arr1 = (char **)malloc(sizeof(char *) * (so_long->height + 1));
	if (!arr1)
		exit(1);
	while (i < so_long->height)
	{
		arr1[i] = ft_strdup(so_long->map[i]);
		i++;
	}
	arr1[i] = NULL;
	if (position1(arr1, so_long->player_x, so_long->player_y) == 0)
	{
		ft_printf ("Error\nThe player has no way out.\n");
		exit (0);
	}
	i = 0;
	while (arr1[i])
		free(arr1[i++]);
	free(arr1);
}

void	backtracking(t_list *so_long)
{
	char	**arr1;
	int		i;

	i = 0;
	arr1 = (char **)malloc(sizeof(char *) * (so_long->height + 1));
	if (!arr1)
		exit(1);
	while (i < so_long->height)
	{
		arr1[i] = ft_strdup(so_long->map[i]);
		i++;
	}
	arr1[i] = NULL;
	if (position(arr1, so_long->player_x, so_long->player_y) == 0)
	{
		ft_printf ("Error\nThe player has no way out.\n");
		exit (0);
	}
	i = 0;
	while (arr1[i])
		free(arr1[i++]);
	free(arr1);
}

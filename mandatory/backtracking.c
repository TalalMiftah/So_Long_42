/* Just to mention, before you Snooping on other people's code,
   just be creative and don't be like me. I use the same logic
   to find valid paths for collectibles and Exit, largely I was
   under pressure, but you have enough time to be creative. */

#include "../so_long.h"

int	count_c(char **c) // i use this function to count the number of collectibles every time i call it.
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

int	position1(char **map, int i, int j) // The purpose of this function is to find a valid path to every collectibles.
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

int	position(char **map, int i, int j) // The purpose of this function is to find a valid path to Exit.
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

/* backtracking_col :

   1*	In this function, I copy the content of my map into **arr1 so that I can modify it without changing the main copy of the map (so_long->map).
   2*	Then i call 'position1' function This function assists me in finding a valid path to all collectibles, and the way I use it makes it simple: I use recursion:
   	if c != 0, I return 0 and put "1" in every place the player stands, so I never return to the previous path, and if c == 0, I return 1,
	and since I didn't find a path to all collectibles, it will return 0.
*/
void	backtracking_col(t_list *so_long)
{
	char	**arr1;
	int		i;

	i = 0;
	arr1 = (char **)malloc(sizeof(char *) * (so_long->height + 1)); // 1*
	if (!arr1)
		exit(1);
	while (i < so_long->height)
	{
		arr1[i] = ft_strdup(so_long->map[i]);
		i++;
	}
	arr1[i] = NULL;
	if (position1(arr1, so_long->player_x, so_long->player_y) == 0) //2*
	{
		ft_printf ("Error\nThe player has no way out.\n");
		exit (0);
	}
	i = 0;
	while (arr1[i])
		free(arr1[i++]);
	free(arr1);
}

/* backtracking :

   1*	In this function, I copy the content of my map into **arr1 so that I can modify it without changing the main copy of the map (so_long->map).
   2*	Then i call 'position' function This function assists me in finding a valid path to exit, and the way I use it makes it simple: I use recursion:
   	if I find "1," I return 0 and put "1" in every place the player stands, so I never return to the previous path, and if I find "E," I return 1,
	and since I didn't find a path, it will return 0.
*/
void	backtracking(t_list *so_long)
{
	char	**arr1;
	int		i;

	i = 0;
	arr1 = (char **)malloc(sizeof(char *) * (so_long->height + 1)); // 1*
	if (!arr1)
		exit(1);
	while (i < so_long->height)
	{
		arr1[i] = ft_strdup(so_long->map[i]);
		i++;
	}
	arr1[i] = NULL;
	if (position(arr1, so_long->player_x, so_long->player_y) == 0) // 2*
	{
		ft_printf ("Error\nThe player has no way out.\n");
		exit (0);
	}
	i = 0;
	while (arr1[i])
		free(arr1[i++]);
	free(arr1);
}

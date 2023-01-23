#include "../so_long.h"

void	width_check(t_list *so_long)
{
	int	j;

	j = 1;
	while (j < so_long->height)
	{
		if (ft_strlen(so_long->map[0]) != ft_strlen(so_long->map[j]))
		{
			ft_printf("Error\n༽◺_◿༼\n");
			exit(1);
		}
		j++;
	}
	so_long->width = ft_strlen(so_long->map[0]);
}

void	frame_check(t_list *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->width)
	{
		if (so_long->map[0][i] != '1' ||
			so_long->map[so_long->height - 1][i] != '1')
		{
			ft_printf("Error\nThe frame of your map must contain only \'1\'\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < so_long->height)
	{
		if (so_long->map[i][0] != '1' ||
			so_long->map[i][so_long->width - 1] != '1')
		{
			ft_printf("Error\nThe frame of your map must contain only \'1\'\n");
			exit(1);
		}
		i++;
	}
}

void	content(t_list *so_long)
{
	so_long->i = 0;
	while (so_long->map[so_long->i])
	{
		so_long->j = 0;
		while (so_long->map[so_long->i][so_long->j])
		{
			if (so_long->map[so_long->i][so_long->j] != 'E' &&
			so_long->map[so_long->i][so_long->j] != 'P' &&
			so_long->map[so_long->i][so_long->j] != 'C' &&
			so_long->map[so_long->i][so_long->j] != '1' &&
			so_long->map[so_long->i][so_long->j] != '0')
			{
				ft_printf("Error\nYour map can contain only P, E, C, 1 or 0!");
				exit(1);
			}
			so_long->j++;
		}
		so_long->i++;
	}
}

void	content_check(t_list *so_long)
{
	so_long->i = 0;
	while (so_long->map[so_long->i])
	{
		so_long->j = 0;
		while (so_long->map[so_long->i][so_long->j])
		{
			if (so_long->map[so_long->i][so_long->j] == 'E')
				so_long->e++;
			if (so_long->map[so_long->i][so_long->j] == 'P')
			{
				so_long->p++;
				so_long->player_x = so_long->i;
				so_long->player_y = so_long->j;
			}
			if (so_long->map[so_long->i][so_long->j] == 'C')
				so_long->c++;
			so_long->j++;
		}
		so_long->i++;
	}
	if (so_long->e != 1 | so_long->p != 1 | so_long->c < 1)
	{
		ft_printf("Error\n");
		exit (0);
	}
}

void	map_check(t_list *so_long)
{
	width_check(so_long);
	frame_check(so_long);
	content(so_long);
	content_check(so_long);
	backtracking(so_long);
	backtracking_col(so_long);
}

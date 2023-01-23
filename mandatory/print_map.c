#include "../so_long.h"

void	map_var(t_list *so_long, char c)
{
	if (c == '1')
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"tools/wall.xpm", &so_long->x, &so_long->y);
	if (c == 'P')
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"tools/P(left).xpm", &so_long->x, &so_long->y);
	if (c == 'C')
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"tools/end_man.xpm", &so_long->x, &so_long->y);
	if (c == 'C' && so_long->c == 1)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"tools/last.xpm", &so_long->x, &so_long->y);
	if (c == 'E' )
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"tools/gate1.xpm", &so_long->x, &so_long->y);
	if (c == 'E' && so_long->c == 0)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"tools/gate0.xpm", &so_long->x, &so_long->y);
	if (!so_long->img)
	{
		ft_printf("Error\nImage name\n");
		exit(1);
	}
}

void	destroy(t_list *so_long)
{
	mlx_destroy_image(so_long->mlx, so_long->img);
	so_long->img = NULL;
}

void	print_grass(t_list *so_long)
{
	so_long->img = mlx_xpm_file_to_image(so_long->mlx,
			"tools/grass0.xpm", &so_long->x, &so_long->y);
	if (!so_long->img)
	{
		ft_printf("Error\nImage name");
		exit(1);
	}
	mlx_put_image_to_window(so_long->mlx, so_long->win,
		so_long->img, so_long->skipx, so_long->skipy);
	destroy(so_long);
}

void	printing(t_list *so_long)
{
	while (so_long->map[so_long->i])
	{
		so_long->j = 0;
		so_long->skipx = 0;
		while (so_long->map[so_long->i][so_long->j])
		{
			if (so_long->map[so_long->i][so_long->j] != '1')
				print_grass(so_long);
			if (so_long->map[so_long->i][so_long->j] != '0')
			{
				map_var(so_long, so_long->map[so_long->i][so_long->j]);
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->img, so_long->skipx, so_long->skipy);
			}
			if (so_long->img)
				destroy(so_long);
			so_long->skipx += 64;
			so_long->j += 1;
		}
		so_long->skipy += 64;
		so_long->i += 1;
	}
}

int	print_map(t_list *so_long)
{
	so_long->skipx = 0;
	so_long->skipy = 0;
	so_long->i = 0;
	so_long->j = 0;
	printing(so_long);
	return (0);
}

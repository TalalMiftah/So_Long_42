#include "../so_long.h"

void	movenemy(t_list *so_long, int x, int y)
{
	int	res;
	int	i;
	int	j;

	i = x;
	j = y;
	x = rand() % 3 - 1;
	y = rand() % 3 - 1;
	res = rand() % 2;
	if (res == 0)
		x = 0;
	else
		y = 0;
	if (so_long->map[i + x][j + y] == 'P')
	{
		ft_printf("\t\t\tYOU DIED (✖╭╮✖)\n");
		exit (0);
	}
	if (so_long->map[i + x][j + y] == '0')
	{
		so_long->map[i + x][j + y] = 'N';
		so_long->map[i][j] = '0';
	}
}

void	print_enemy(t_list *so_long, int i)
{
	if (i <= 20)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"enemy/N0.xpm", &so_long->x, &so_long->y);
	if (i > 20 && i <= 40)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"enemy/N1.xpm", &so_long->x, &so_long->y);
	if (i > 40 && i <= 60)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"enemy/N2.xpm", &so_long->x, &so_long->y);
	if (i > 60 && i <= 80)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"enemy/N3.xpm", &so_long->x, &so_long->y);
	if (i > 80 && i <= 90)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"enemy/N4.xpm", &so_long->x, &so_long->y);
	if (i > 90 && i <= 100)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"enemy/N5.xpm", &so_long->x, &so_long->y);
	if (i > 100 && i <= 120)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"enemy/N9.xpm", &so_long->x, &so_long->y);
	if (i > 120 && i <= 140)
		so_long->img = mlx_xpm_file_to_image(so_long->mlx,
				"enemy/N10.xpm", &so_long->x, &so_long->y);
}

int	animation(t_list *so_long)
{
	static int	j;
	static int	i;

	if (i == 141)
		i = 0;
	print_enemy(so_long, i);
	if (j == 15)
	{
		j = 0;
		movenemy(so_long, so_long->i, so_long->j);
	}
	i++;
	j++;
	return (0);
}

#include "../so_long.h"

void	up(t_list *so_long)
{
	if (so_long->map[so_long->player_x - 1][so_long->player_y] == 'E' &&
		so_long->c == 0)
	{
		ft_printf("\t\t\tYOU WON :)");
		exit(1);
	}
	if (so_long->map[so_long->player_x - 1][so_long->player_y] == 'C')
		so_long->c--;
	if (so_long->map[so_long->player_x - 1][so_long->player_y] != 'E' &&
		so_long->map[so_long->player_x - 1][so_long->player_y] != '1')
	{
		so_long->map[so_long->player_x][so_long->player_y] = '0';
		so_long->map[--so_long->player_x][so_long->player_y] = 'P';
		so_long->move++;
		ft_printf("%d\n", so_long->move);
	}
}

void	left(t_list *so_long)
{
	if (so_long->map[so_long->player_x][so_long->player_y - 1] == 'E' &&
		so_long->c == 0)
	{
		ft_printf("\t\t\tYOU WON :)");
		exit(1);
	}
	if (so_long->map[so_long->player_x][so_long->player_y - 1] == 'C')
		so_long->c--;
	if (so_long->map[so_long->player_x][so_long->player_y - 1] != 'E' &&
		so_long->map[so_long->player_x][so_long->player_y - 1] != '1')
	{
		so_long->map[so_long->player_x][so_long->player_y] = '0';
		so_long->map[so_long->player_x][--so_long->player_y] = 'P';
		so_long->playerImg = "tools/P(left).xpm";
		so_long->move++;
		ft_printf("%d\n", so_long->move);
	}
}

void	down(t_list *so_long)
{
	if (so_long->map[so_long->player_x + 1][so_long->player_y] == 'E' &&
		so_long->c == 0)
	{
		ft_printf("\t\t\tYOU WON :)");
		exit(1);
	}
	if (so_long->map[so_long->player_x + 1][so_long->player_y] == 'C')
		so_long->c--;
	if (so_long->map[so_long->player_x + 1][so_long->player_y] != 'E' &&
		so_long->map[so_long->player_x + 1][so_long->player_y] != '1')
	{
		so_long->map[so_long->player_x][so_long->player_y] = '0';
		so_long->map[++so_long->player_x][so_long->player_y] = 'P';
		so_long->move++;
		ft_printf("%d\n", so_long->move);
	}
}

void	right(t_list *so_long)
{
	if (so_long->map[so_long->player_x][so_long->player_y + 1] == 'E' &&
		so_long->c == 0)
	{
		ft_printf("\t\t\tYOU WON :)\n");
		exit(1);
	}
	if (so_long->map[so_long->player_x][so_long->player_y + 1] == 'C')
		so_long->c--;
	if (so_long->map[so_long->player_x][so_long->player_y + 1] != 'E' &&
		so_long->map[so_long->player_x][so_long->player_y + 1] != '1')
	{
		so_long->map[so_long->player_x][so_long->player_y] = '0';
		so_long->map[so_long->player_x][++so_long->player_y] = 'P';
		so_long->playerImg = "tools/P(right).xpm";
		so_long->move++;
		ft_printf("%d\n", so_long->move);
	}
}

int	move(int key, t_list *so_long)
{
	if (key == 53)
	{
		ft_printf("OH MAN YOU JUST RUINING IT :(\n");
		mlx_clear_window(so_long->mlx, so_long->win);
		exit (0);
	}
	if (key == 13 || key == 126)
		up(so_long);
	if (key == 0 || key == 123)
		left(so_long);
	if (key == 1 || key == 125)
		down(so_long);
	if (key == 2 || key == 124)
		right(so_long);
	print_map(so_long);
	return (0);
}

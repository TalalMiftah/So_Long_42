#include"../so_long.h"

int	closewin(t_list *so_long)
{
	ft_printf("OH MAN YOU JUST RUINING IT :(\n");
	mlx_clear_window(so_long->mlx, so_long->win);
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	so_long;

	so_long.i = 0;
	so_long.j = 0;
	so_long.p = 0;
	so_long.e = 0;
	so_long.c = 0;
	so_long.move = 0;
	so_long.height = 0;
	if (ac != 2)
		exit (0);
	map_valid(av[1], &so_long);
	so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx, so_long.width * 64,
			so_long.height * 64, "Farm");
	if (!so_long.mlx || !so_long.win)
		exit(1);
	print_map(&so_long);
	mlx_hook (so_long.win, 2, 1L << 0, move, &so_long);
	mlx_hook (so_long.win, 17, 1L << 0, closewin, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}

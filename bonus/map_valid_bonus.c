#include "../so_long.h"

void	extention_check(char *name)
{
	if (ft_strcmp(name + ft_strlen(name) - 4, ".ber") != 0)
	{
		ft_printf ("Error\nMap file must ending with the .ber extension\n");
		exit(1);
	}
}

void	map_height(char *name, t_list *so_long)
{
	int		fd;
	char	r;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("Error\nFd issue!");
		exit(1);
	}
	while (read(fd, &r, 1))
	{
		if (r == '\n')
			i++;
	}
	so_long->height = i;
	if (so_long->height == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	so_long->height++;
}

void	read_map(char *name, t_list *so_long)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("Error\nfd issue\n");
		exit(1);
	}
	so_long->map = (char **)ft_calloc(so_long->height + 1, sizeof(char *));
	if (!so_long->map)
		exit(1);
	while (i < so_long->height)
		so_long->map[i++] = get_next_line(fd);
	close (fd);
}

void	map_valid(char *name, t_list *so_long)
{
	extention_check(name);
	map_height(name, so_long);
	read_map(name, so_long);
	map_check(so_long);
	if (so_long->height == so_long->width
		|| so_long->height == 0
		|| so_long->width == 0)
	{
		ft_printf("Error\nCheck your map please!!!");
		exit(1);
	}
}

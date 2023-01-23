#include "../so_long.h"

int	ft_strcmp(char *c1, char *c2)
{
	size_t			i;

	i = 0;
	while (c1[i] != '\0' || c2[i] != '\0')
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if ((size != 0) && (((size * count) / size) != count))
		return (NULL);
	str = malloc(count * size);
	if (!str)
		exit(1);
	ft_bzero(str, count * size);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = s;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}

void	you_won(t_list *so_long)
{
	ft_printf("\t\t\tYOU WON :)");
	mlx_clear_window(so_long->mlx, so_long->win);
	exit(0);
}

void	game_ended(t_list *so_long)
{
	ft_printf("\t\t\tYOU DIED (✖╭╮✖)\n");
	mlx_clear_window(so_long->mlx, so_long->win);
	exit (0);
}

#include "../so_long.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i += write(1, "-2147483648", 11);
	if (n < 0 && n >= -2147483647)
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
		i += ft_putchar(n + 48);
	return (i);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static int	ft_out(va_list list, const char *s, int i)
{
	int	count;

	count = 0;
	if (s[i] == '%')
		count += ft_putchar(s[i]);
	else if (s[i] == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (s[i] == 'd' || s[i] == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (s[i] == 's')
		count += ft_putstr(va_arg(list, char *));
	else
		count += ft_putchar(s[i]);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		ln;

	i = 0;
	ln = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] != '%')
			ln += ft_putchar(s[i]);
		else if (s[i] == '%')
		{
			i++;
			if (!s[i])
				return (ln);
			ln += ft_out(list, s, i);
		}
		i++;
	}
	va_end(list);
	return (ln);
}

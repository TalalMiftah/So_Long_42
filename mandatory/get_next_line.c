#include "../so_long.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*s1;

	i = ft_strlen(s) + 1;
	s1 = malloc(i);
	if (!s1)
		exit(1);
	i = 0;
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_read(int fd, char *str)
{
	int		bytes;
	char	*buff;

	bytes = 1;
	buff = malloc(2);
	if (!buff)
		exit(1);
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, 1);
		if (bytes == -1)
		{
			free (buff);
			free (str);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*c;

	if (fd < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	c = ft_rhyme(str);
	str = next_ryhme(str);
	return (c);
}

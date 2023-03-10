#include "../so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*c1;
	ssize_t		i;
	ssize_t		r;

	i = -1;
	r = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	c1 = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!c1)
		exit(1);
	while (s1[++i])
		c1[i] = s1[i];
	while (s2[r])
		c1[i++] = s2[r++];
	free(s1);
	return (c1);
}

char	*ft_rhyme(char *s)
{
	ssize_t	i;
	char	*rhyme;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	rhyme = malloc(i + 1);
	if (!rhyme)
		exit(1);
	rhyme[i--] = 0;
	while (i >= 0)
	{
		rhyme[i] = s[i];
		i--;
	}
	return (rhyme);
}

char	*next_ryhme(char *str)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = malloc (ft_strlen(str) - i + 1);
	if (!s)
		exit(1);
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}

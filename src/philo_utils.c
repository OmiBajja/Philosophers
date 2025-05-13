
#include <philosophers.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
void	ft_freestrs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
	return ;
}

char	**ft_strsdup(char **src, size_t size)
{
	size_t	i;
	char	**cpy;

	i = 0;
	cpy = (char **)malloc((size + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	while (i < size)
	{
		cpy[i] = ft_strdup(src[i]);
		if (!cpy[i])
		{
			ft_freestrs(cpy);
			return (NULL);
		}	
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	s;

	i = 0;
	n = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*src;
	size_t	i;

	i = 0;
	if (elementSize != 0 && elementCount > 18446744073709551615UL / elementSize)
		return (NULL);
	src = malloc(elementCount * elementSize);
	if (!src)
		return (NULL);
	while (i < elementCount * elementSize)
	{
		((char *)src)[i] = 0;
		i++;
	}
	return (src);
}

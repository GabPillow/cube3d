#include "libft.h"

size_t	ft_strlenn(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

#include "../inc/libunit.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != 0)
		i++;
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

char	*ft_strdup(const char *s1)
{
	int		strlen;
	char	*return_p;
	char	*dest;

	strlen = ft_strlen(s1);
	return_p = malloc(sizeof(char) * strlen + 1);
	if (!return_p)
		return (return_p);
	dest = return_p;
	while (*s1)
		*dest++ = *s1++;
	*dest = 0;
	return (return_p);
}

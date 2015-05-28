#include <common.h>

int			str_issort(const char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) > 5)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}
